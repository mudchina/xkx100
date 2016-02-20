// Room: /city/daxiao.c

inherit ROOM;

int sos(int,int);
void fresh(object);

void create()
{
	set("short", "赌场");
	set("long", @LONG
这里是赌(gamble)「大小」的房间，墙上挂着一块牌子 (paizi)。
南边是赌场的大堂。
LONG );

	set("item_desc", ([
		"paizi" : 

"本赌场新开放赌「大小」正处于测试阶段。\n"
"「大小」赌法：\n"
"共用三粒色子撒在一只碗里，色子点数总和：\n"
"	四 至 十 为「小」，\n"
"	十一 至 十七 为「大」，\n"
"	三粒色子点数相同，则大小通吃。\n"
"\n开大赔大，开小赔小，一赔一。\n"
"\n本赌场接受各种货币及功夫的点数为赌注。\n",
	]));

	set("exits", ([
                "south" : __DIR__"duchang",
//                "north" : __DIR__"daxiao2",
	]));
	set("no_clean_up", 0);
        set("no_fight", "1");
        set("gamble_room", "1");
	set("coor/x", -210);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
}
/*

void init()
{
	add_action("do_gamble", "gamble");
}

int do_gamble(string arg)
{
	int a,b,c;
	int wager, skill, lpoint, tpoint,skill2,newskill;
	string wtype1, wtype2, wtype0, wtype3, status;
	object mtype, me;
	mapping lrn;

	int min, max;
	min = 50;
        max = 2000;

	me = this_player();

	if (me->query_temp("casino/mark"))
		return notify_fail("你这么着急啊? 还是再多休息一会儿吧 -:)\n");

	if (!arg || sscanf(arg, "%s %s %s %d %s", wtype0, wtype1, wtype2, wager,wtype3) <4)
        return notify_fail("gamble big|small money|skill <type> <amount> (another skill)\n"
"eg. gamble big money silver 3 OR gamble small skill dodge 10\n"+
"或：gamble small skill taiji-jian 2000 yunlong-jian\n");
	newskill=1;
	if (wtype1 == "money")
	{
		mtype = present(wtype2 + "_money", me);
		if( !mtype)          return notify_fail("你身上没有这种货币。\n");
		if( wager < 1 )        return notify_fail("你要压多少啊?\n");
		if( (int)mtype->query_amount() < wager)
			return notify_fail("你身上没有那么多" + mtype->query("name") + "。\n");
		if( wager*(mtype->query("base_value")) < min ||
		    wager*(mtype->query("base_value")) > max )
			return notify_fail("你的赌注不在限额之内!\n"
			"这里的限额是" + chinese_number(min) + "至" + chinese_number(max) + "。\n");
	}
	else if (wtype1 == "skill")
	{
		skill = me->query_skill(wtype2, 1);
		if( skill < 1 )
                return notify_fail("你要诈赌啊? 你根本不会这项功夫!\n");
		skill2= me->query_skill(wtype3, 1);
		if( skill2 < 1 )
		{
		if(skill2==0) message_vision("你不会赌别的功夫。\n", me);
		else message_vision("你不会"+wtype3+"这项功夫!\n", me);
		message_vision("只能赌"+to_chinese(wtype2)+"这项功夫了。\n", me);
		newskill=0;
		}		
		if(skill2>=1)
                {
//		if(strsrch(wtype2,"-")<=0)	return notify_fail("对不起,换赌技能只能赌高级功夫。\n");
		return notify_fail("对不起,换赌技能暂时关闭了。\n");
		}

                lrn = me->query_learned(wtype2, 1);
		lpoint = (int)lrn[wtype2];

//		message_vision("learned pt: " + lpoint + "\n", me);
		tpoint = lpoint + sos(1, skill);
//		message_vision("total learned pt: " + tpoint + "\n", me);
		if (wager > tpoint) return notify_fail("你赌不起!\n");
		if (wager < min || wager > max)
			return notify_fail("你的赌注不在限额之内!\n"
			"这里的限额是" + chinese_number(min) + "至" + chinese_number(max) + "。\n");
	}
	else	return notify_fail("本赌场不接受这种赌注。\n");

        if ( (wtype0 != "big") && (wtype0 != "small") )
                return notify_fail("你要赌大还是赌小?\n");

	me->set_temp("gamb_t",(me->query_temp("gamb_t") +1));
        if (me->query_temp("gamb_t") > 50)
	{
		call_out("fresh", 300, me);
		me->set_temp("casino/mark", 1);
		return notify_fail(
"这位" + RANK_D->query_respect(me) + "，你已经赌了很久了，还是先休息一会儿吧。\n");
	}

	a = random(6) + 1;
	b = random(6) + 1;
	c = random(6) + 1;

	message_vision("开：" + a + "	" + b + "   " + c + "   ，", me);

	if ((a == b) && (b == c) )
		message_vision("大小通杀。\n", me);
	else if ( (a+b+c) > 10 )
		message_vision("吃小赔大。\n",me);
	else if ( (a+b+c) < 11 )
		message_vision("吃大赔小。\n",me);

	if ( ( (a == b) && (b == c) ) ||
   	     ( (a+b+c) > 10 && (wtype0 == "small") ) ||
	     ( (a+b+c) < 11 && (wtype0 == "big") ) )
		status = "lose";

	if (wtype1 == "money")
	{
		if ( status == "lose") {
        message_vision(me->query("name") + "输了" + chinese_number(wager) +
mtype->query("base_unit") + mtype->query("name") + "。\n", me);
                        mtype->set_amount((int)mtype->query_amount() - wager);
                        mtype->move(me);
                }
		else {
        message_vision(me->query("name") + "赢了" + chinese_number(wager) +
mtype->query("base_unit") + mtype->query("name") + "。\n", me);
                        mtype->set_amount((int)mtype->query_amount() + wager);
                        mtype->move(me);
                }
	}
	else if (wtype1 == "skill")
	{
		if ( status == "lose") {
	newskill=0;
        message_vision(me->query("name") + "输了" + chinese_number(wager) +
"点" + to_chinese(wtype2) + "的功力。\n", me);
			wager -= lpoint;
			while (wager > 0)
			{
			   wager -= skill*skill;
			   skill -= 1;
			}
			wager *= -1;
			if (wager > lpoint) wager -= lpoint;
			else wager += (lpoint*-1);
		}
		else {
	if(newskill==0)
        message_vision(me->query("name") + "赢了" + chinese_number(wager) +
"点" + to_chinese(wtype2) + "的功力。\n", me);
	else
	{
        message_vision(me->query("name") + "赢了" + chinese_number(wager/2) +
"点" + to_chinese(wtype3) + "的功力。\n", me);
	skill = me->query_skill(wtype3, 1);
	lrn = me->query_learned(wtype3, 1);
	lpoint = (int)lrn[wtype3];
	tpoint = lpoint + sos(1, skill);
	wager=wager/2;
	}
			wager += lpoint;
			while (wager >= (skill+1)*(skill+1))
			{
                          skill += 1;
			  wager -= skill*skill;
			}
			wager -= lpoint;
		}
                if(newskill==0) 
		{
		me->set_skill(wtype2, skill);
		me->improve_skill(wtype2, wager);
		}
                else 
		{
		me->set_skill(wtype3, skill);
		me->improve_skill(wtype3, wager);
		}
	}
	me->start_busy(2);
	return 1;
}

void fresh(object ob)
{
	ob->delete_temp("gamb_t");
	ob->delete_temp("casino/mark");
}

int sos(int lower, int upper)
{
	int x,y;
	x = 0;

        while (lower <= upper)
	{
		y = lower*lower;
		x += y;
		lower++;
	}
	return x;
}
*/
