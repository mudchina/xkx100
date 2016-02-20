// Room: /d/jiaxing/diaoyu.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "钓鱼亭");
	set("long", @LONG
湖边一座石砌的精致小亭。极目远眺，碧水连天，波光潋滟。近处
游鱼唼喋，漾起一圈圈涟漪。
LONG
	);
	set("outdoors", "jiaxing");
	set("no_fight",1);
	set("no_steal",1);
	set("no_sleep",1);
	set("no_beg",1);
	set("fish",200);
	set_temp("char_count",2);

	set("exits", ([
		"south" :  __DIR__"nanhu",
	]));
	set("coor/x", 1510);
	set("coor/y", -990);
	set("coor/z", 0);
	setup();
}

void init()

{
	add_action("do_diao","diao");
	add_action("do_ban","dazuo");
	add_action("do_ban","tuna");
	add_action("do_ban","du");
	add_action("do_ban","study");
	add_action("do_ban","exercise");
	add_action("do_shuohua","say");
	add_action("do_shuohua","whisper");
	add_action("do_shuohua","reply");
	add_action("do_shuohua","tell");

}
int do_shuohua()
{
	write ("别说话！别把鱼吓走了！\n");
	return 1;
}
int do_ban()
{
	write ("别妨碍人家钓鱼！\n");
	return 1;
}
int do_diao(string arg)
{
	object me = this_player();
	int bonus,exp,pot;
	object mon;

//	if((int)(me->query("combat_exp")) > 15000)
//	      return notify_fail("你的经验太高了，这里不适合你。\n");
	if (query_temp("char_count") < 1)
	      return notify_fail("这里太拥挤了。没处下钩。回头再来吧。\n");
	if (query("fish") < 1)
	      return notify_fail("这里的鱼钓得差不多了，半天看不到鱼影。回头再来吧。\n");
	if (!arg)
	      return notify_fail("你要钓什么？\n");
	if (arg != "fish" && arg != "鱼")
	      return notify_fail("你可不是姜太公，没指望钓到别的。\n");
	if( (int)me->query_temp("fishing") ) 
	      return notify_fail("你已经在钓鱼了。\n");
	if ((int)(me->query("qi")) < 16)	
	      return notify_fail("你已经太累了，还是休息一下吧。\n");
	message_vision("
$N将鱼饵挂在钩上，轻轻一荡鱼竿，将鱼饵扔进水里。\n\n",me);
	me->set_temp("fishing",1);
	add_temp("char_count", -1);
	add("fish", -1);
	me->add("qi",-10);

	call_out("del_fishing", 6, me, mon, bonus, exp, pot);
	return 1;
}

void del_fishing(object me, object mon, int bonus, int exp, int pot)
{
	me->delete_temp("fishing");
	add_temp("char_count", 1);
	if (random (10) < 2)
	{
		message_vision(HIY"
只见浮漂微微一动，$N赶紧用力提竿，提上来一看，白白的鱼钩上什么也
没有。唉，太心急了，没等鱼儿吃钩就早早提竿了。\n"NOR,me);
		me->start_busy(3);
		return ;
	}
	else
	{
		exp = 2 + random(6);
		pot = 1 + random(3);
		message_vision(HIW"
浮漂在动了，$N屏息静气，死死盯住浮漂，不敢有丝毫大意，只见浮漂猛
地往下一沉，$N抓住时机一提竿，$N钓起了一条" + chinese_number(exp) + "斤重的鱼。\n\n"NOR 
"$N身旁突然钻出一个鱼贩，一把将$N手中的鱼夺走，顺手扔给$N一锭银子。\n",me);
//	bonus = (int) me->query("combat_exp");
//	bonus += exp;
//	me->set("combat_exp", bonus);
//	bonus = (int) me->query("potential");
//	bonus += exp;
//	me->set("potential", bonus);
		mon = new("/clone/money/silver");
		mon->set_amount(exp);
		mon->move(me);
		me->start_busy(3);

		return;
	}
}