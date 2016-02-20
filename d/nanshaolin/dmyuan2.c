// Room: /d/nanshaolin/dmyuan2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void init()
{
	add_action("lingwu","lingwu");
}

void create()
{
	set("short", "达摩院后殿");
	set("long", @LONG
这是一座古朴的殿堂。西首的墙上挂满了各类武功图谱，不少白须
白眉的老僧们正端坐在图谱画轴之前，似乎在苦苦思索。南北山墙是高
及屋顶的大书架，走近细看，它们是各门各派的武功秘笈，屋正中摆着
几张矮几诃和几个团，几位老僧正在入定中。
LONG );
	set("exits", ([
		"south" : __DIR__"dmyuan",
	]));
	set("coor/x", 1790);
	set("coor/y", -6080);
	set("coor/z", 20);
	setup();
}

int lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl;

	if (!me->query("muren_winner"))
		return notify_fail("你未过木人巷，不能在此领悟。\n");
	if (!arg) return notify_fail("你要领悟什么？\n");
	if (!me->query_skill(arg,1))
		return notify_fail("你不会这种技能。\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (arg == "force" )
		return notify_fail("你无法领悟基本内功。\n");
	if ((int)me->query("potential") -(int)me->query("learned_points") < 1 ) 
		return notify_fail("你从实战中得到的潜能已经用完了。\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("你只能从特殊技能中领悟。\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") ||
		me->query("jing")*100/me->query("max_jing") < 50)
	{
		me->receive_damage("jing",bl/5);
		return notify_fail("你没办法集中精神。\n");
	}
	sl=me->query_skill(special,1);
	if (sl > 200)
		return notify_fail("你的" +to_chinese(special)+"造诣已经很高了，不必再在这里领悟什么了。\n");
	if (bl > sl)
		return notify_fail("你的" +to_chinese(special)+"造诣不够，无法领悟更深一层的"+to_chinese(arg)+"。\n");
	write("你瞑思苦想，对"+to_chinese(arg)+"的体会又深了一层。\n");
	if ((int)me->query("combat_exp",1) >850000)
	{
		me->receive_damage("jing",bl/5*3);
		me->add("learned_points", 1);
		me->improve_skill(arg, me->query_int()*3/2);
		me->start_busy(1);
		return 1;
	}
	me->receive_damage("jing",bl/5*2);
	me->add("learned_points", random(2));
	me->improve_skill(arg, me->query_int()*3/2);
	me->start_busy(1);
	return 1;
}

