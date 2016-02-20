// gamble.c

inherit F_CLEAN_UP;

int sos(int,int);
void fresh(object ob);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int a,b,c;
	int wager, skill, lpoint, tpoint;
	string wtype1, wtype2, wtype0, status;
	object mtype;
	mapping lrn;

	int min, max;
	min = 50;
	max = 1500;

	if (me->query_temp("casino/mark"))
		return notify_fail("你这么着急啊？还是再多休息一会儿吧 -:)\n");

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，先等会瞧瞧吧。\n");

	if (!environment(me)->query("gamble_room"))
		return notify_fail("想赌当然要在赌场了！\n");

	if (!arg || sscanf(arg, "%s %s %s %d", wtype0, wtype1, wtype2, wager) !=4)
	return notify_fail("gamble big|small money <type> <amount>\n"
"eg. gamble big money silver 3\n");

	if (wtype1 == "money")
	{
		mtype = present(wtype2 + "_money", me);
		if( !mtype) return notify_fail("你身上没有这种货币。\n");
		if( wager < 1 ) return notify_fail("你要压多少啊?\n");
		if( (int)mtype->query_amount() < wager)
			return notify_fail("你身上没有那么多" + mtype->query("name") + "。\n");
		if( wager*(mtype->query("base_value")) < min ||
		    wager*(mtype->query("base_value")) > max )
			return notify_fail("你的赌注不在限额之内！\n"
			"这里的限额是" + chinese_number(min) + "至" + chinese_number(max) + "。\n");
	}
/*	else if (wtype1 == "skill")
	{
		skill = me->query_skill(wtype2, 1);
		if( skill < 1 )
		return notify_fail("你要诈赌啊? 你根本不会这项功夫!\n");
		lrn = me->query_learned(wtype2, 1);
		lpoint = (int)lrn[wtype2];
//		message_vision("learned pt: " + lpoint + "\n", me);
		tpoint = lpoint + sos(1, skill);
//		message_vision("total learned pt: " + tpoint + "\n", me);
		if (wager > tpoint) return notify_fail("你赌不起!\n");
		if (wager < min || wager > max)
			return notify_fail("你的赌注不在限额之内！\n"
			"这里的限额是" + chinese_number(min) + "至" + chinese_number(max) + "。\n");
	}
*/
	else    return notify_fail("本赌场不接受这种赌注。\n");

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

	message_vision("开：" + a + "   " + b + "   " + c + "   ，", me);

	if ((a == b) && (b == c) )
//	      message_vision("开：" + a + " " + b + " " + c " ,大小通杀。\n", me);
		message_vision("大小通杀。\n", me);
	else if ( (a+b+c) > 10 )
//		message_vision("开：" + a + " " + b + " " + c " ,吃小赔大。\n", me);
		message_vision("吃小赔大。\n",me);
	else if ( (a+b+c) < 11 )
//		message_vision("开：" + a + " " + b + " " + c " ,吃大赔小。\n", me);
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
/*	else if (wtype1 == "skill")
	{
		if ( status == "lose") {
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
	message_vision(me->query("name") + "赢了" + chinese_number(wager) +
"点" + to_chinese(wtype2) + "的功力。\n", me);
			wager += lpoint;
			if (wager >= (skill+1)*(skill+1))
			{
			  skill += 1;
//			  wager -= skill*skill;
			  wager = 0;
			}
			wager -= lpoint;
		}
		me->set_skill(wtype2, skill);
		me->improve_skill(wtype2, wager);
		if (wager > 1)
			me->improve_skill("gambling",(int)(me->query("int")/5));
	}
*/
	me->start_busy(1);
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

int help(object me)
{
	write(@Help
指令格式: gamble <big | small> <money> <type> <amount>>

    这是在赌场赌博的命令。
    你可以指定赌大还是赌小（big | small），并用钱做赌注。
Help
	);
	return 1;
}

