// Room: /city/wudao.c
// Date: Feb.28 1998 by Java
#include <ansi.h>
inherit ROOM;
string look_gaoshi();
string look_pai();
int  clear_title(string arg);
int sort(string arg);
void add_title(object me,string arg);
void create()
{
	set("short", "武道场");
	set("long", @LONG
这里是比武大会巫师席，高据擂台之上，雕梁琉瓦，花木游栏。四
望青山迎爽，向下看擂台周围人头攒动。桌上放着一块小木牌 (pai)，
后壁上贴着一张红纸告示(gaoshi)。
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
		"pai"    : (: look_pai :),
	]));
	set("exits", ([
		"down"      : __DIR__"leitai",
	]));
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("coor/x", -20);
	set("coor/y", -30);
	set("coor/z", 20);
	setup();
//	replace_program(ROOM);
}
string look_pai()
{
	return 
"\n
"HIR"(擂台上)start id1 id2  "HIY"----  擂台上之玩家开始比武。
"HIR"load     <player id>   "HIY"----  拉玩家上擂台。
"HIR"kick     <player id>   "HIY"----  踢玩家下擂台。
"HIR"heal     <player id>   "HIY"----  给擂台上玩家恢复。
"HIR"sort id1 id2 id3 ...   "HIY"----  给参赛玩家经验排序

"HIG"titles  <player id> a1 "HIY"----  赠玩家天下第一侠少 (20以下)。
"HIG"titles  <player id> a2 "HIY"----  赠玩家天下第二侠少 (20以下)。
"HIG"titles  <player id> b1 "HIY"----  赠玩家天下名侠     (exp<1m)。
"HIG"titles  <player id> c1 "HIY"----  赠玩家天下名侠  (3m>exp>1m)。 
"HIG"titles  <player id> d1 "HIY"----  赠玩家天下名侠  (5m>exp>3m)。
"HIG"titles  <player id> e1 "HIY"----  赠玩家天下第二大侠 (10m>exp>5m)。
"HIG"titles  <player id> f1 "HIY"----  赠玩家天下第一大侠 (exp>10m)。

\n"NOR;
}
string look_gaoshi()
{
	return 
HIG"\n请用help biwu了解比武规则。
\n"NOR;
}
void init()
{
	if(wizardp(this_player()))
	{
		add_action("do_load", "load");
		add_action("do_kick", "kick");
		add_action("do_heal", "heal");
		add_action("do_sort", "sort");
		add_action("do_titles", "titles");
	}
}
int do_sort(string arg)
{
	string *list;
	object *fighter=({});
	object ob;
	int i,j;
	int *exp;
	string *name;
	
	if (!arg) return 0;
	list = explode(arg," ");
	for (i=0,j=0;i<sizeof(list);i++)
	{
		ob=find_player(list[i]);
		if (!objectp(ob))
			ob=NPC_D->create_player(list[i]);
		if (objectp(ob)) 
			fighter += ({ob});
	}
	fighter = sort_array(fighter,(: $1->query("combat_exp") - $2->query("combat_exp") :));
	write("排名如下：\n");
	j= sizeof(fighter);
	while(j--)
	{
		write(sprintf("%20s %9d\n",fighter[j]->query("name")+"("+fighter[j]->query("id")+")",fighter[j]->query("combat_exp")));
		if (!objectp(environment(fighter[j])))
		destruct(fighter[j]);
	}
	return 1;
}
int valid_leave(object me, string dir)
{
        if( dir=="down"  )
      {
      		me->set_temp("view_leitai",0);
	        me->set("no_get",1);
	    }
        return ::valid_leave(me, dir);
}

int do_load(string arg)
{
	object ob, me;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: loadup <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("没这个人耶。\n");
	message_vision(HIG"$N拉"+ob->name()+"上擂台。\n"NOR, me);
	message_vision(HIG"$N双腿一蹬，腾空而起，轻轻落在擂台边上，衣袂襟风，十分潇洒。\n"NOR, ob);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n发什么呆呀你，先上来吧给我。\n"NOR);
	ob -> move("/d/city/leitai");
	ob -> delete_temp("view_leitai");
	ob -> delete("env/combatd");
	message_vision(HIG"$N腾空落在擂台边上，衣袂襟风，十分潇洒。\n"NOR, ob);
	return 1;
}
int do_kick(string arg)
{
	object ob, me;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: kickdown <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("没这个人耶。\n");
	message_vision(HIG"$N把"+ob->name()+"踢下擂台。\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	message_vision(HIG"只听得$N嗷的一声，飞身跳下擂台去了。\n"NOR, ob);
	tell_object(ob,HIR"\n没玩够啊，先下去吧你给我。\n"NOR);
	ob -> move("/d/city/wudao1");
	ob -> set_temp("view_leitai",1);
	message_vision(HIG"只见$N长呼声中，一个大屁股墩坐在地上唉唉不绝。\n"NOR, ob);
	return 1;
}
int do_heal(string arg)
{
	object ob, me, obj;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: heal <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("没这个人耶。\n");

	tell_object(me, HIG"你为"+ob->name()+"恢复比武状态。\n"NOR);
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("neili", ob->query("max_neili"));
	ob->clear_condition();
	tell_object(ob,HIR"\n为你恢复了比武状态。可以出手了。\n"NOR);
	return 1;
}
int do_titles(string arg)
{
	object obj, me=this_player();
	string dest, topic;
	object ob1,ob2;

	if( !arg || sscanf(arg, "%s %s", dest, topic)!=2 )
		return notify_fail("你要封谁什么称号？\n");
	obj = find_player(dest);
	if(!obj || !me->visible(obj)) return notify_fail("没有这个人....。\n");
	switch (topic)
	{
                case "a1": 
                	add_title(obj, "天下第一侠少"); 
                	ob1 = new("/u/biwu/puti-zi");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(100);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "a2": 
                	add_title(obj, "天下第二侠少");
                	ob1 = new("/u/biwu/puti-zi");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(50);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "b1": 
                	add_title(obj, "天下名侠之神功盖世"); 
                	ob1 = new("/u/biwu/bing6");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(200);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "c1": 
                	add_title(obj, "天下名侠之武学宗师");
                	ob1 = new("/u/biwu/bing6");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(200);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "d1": 
                	add_title(obj, "天下名侠之一代天骄");
                	ob1 = new("/u/biwu/bing6");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(200);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "e1": 
                	add_title(obj, "武林泰斗");
                	ob1 = new("/u/biwu/bing6");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(200);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "f1": 
                	add_title(obj, "武林至尊");
                	ob1 = new("/u/biwu/bing6");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(200);
                	ob1->move(me);
                	ob2->move(me);
                	break;
		default: break;
	}
	message_vision(HIG"$N授"+obj->name()+"封号，奖品已交到你手上。\n"NOR, me);
	tell_object(obj,me->query("name")+"授予你封号，请等待发放奖品。\n");
	return 1;
}
void add_title(object me,string arg)
{
        string title;
        title=arg+clear_title(me->query("title"));
        me->set("title",title);
}
string clear_title(string arg)
{
        if( (strsrch(arg, "天下第一侠少") >= 0) ||
            (strsrch(arg, "天下第二侠少") >= 0) ||
            (strsrch(arg, "天下名侠之神功盖世") >= 0) ||
            (strsrch(arg, "天下名侠之武学宗师") >= 0) ||
            (strsrch(arg, "天下名侠之一代天骄") >= 0) ||
            (strsrch(arg, "武林泰斗") >= 0) ||
            (strsrch(arg, "武林至尊") >= 0))
                {
                arg = replace_string(arg, "天下第一侠少","");
                arg = replace_string(arg, "天下第二侠少","");
                arg = replace_string(arg, "天下名侠之神功盖世","");
                arg = replace_string(arg, "天下名侠之武学宗师","");
                arg = replace_string(arg, "天下名侠之一代天骄","");
                arg = replace_string(arg, "武林泰斗","");
                arg = replace_string(arg, "武林至尊","");
        }
        return arg;
}
