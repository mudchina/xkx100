// Room: /d/gumu/jingxiu.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIC"石室"NOR);
	set("long", @LONG
此地供各弟子打坐静修之用。地上仅有几个蒲团，几个古墓弟子正
在闭目领悟。正面的石墙( qiang)上刻着不少文字, 仔细一看，原来都
抄录着四书五经等古籍，用来给古墓弟子提高修养。
LONG	);

	set("exits", ([
		"south" : __DIR__"mudao21",
	]));
	set("item_desc", ([
		"qiang" : "墙上写满了各种古籍文字。\n",
	]));
	set("coor/x", -3190);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
}

void init()
{ 
	add_action("do_think", "think");
	add_action("do_think", "lingwu");
}

int do_think(string arg)
{
	mapping fam;
	object me = this_player();

	if ( !living(me) ) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");
	if (arg == "qiang" || arg == "wall")
	{
		if ((int)me->query("jing") < 20 )
			return notify_fail("你觉得好累,好想睡觉。\n");
		if ( me->query_skill("literate", 1) > 140)
			return notify_fail("你已经完全读懂了墙上的文字。\n");
		if ( me->query_skill("literate", 1) > 10 &&
			me->query_skill("literate", 1) > me->query("combat_exp")/1000)
			return notify_fail("你的经验不够，不能读懂墙上的文字。\n");
		if (me->query("potential", 1) - me->query("learned_points") < 1)
			return notify_fail("你没潜能了，不能再继续修习了。\n");
		me->add("learned_points", 1);
		me->receive_damage("jing", 5 + random(10));
		me->improve_skill("literate", random(me->query_int()));
		write("你对着石壁，仿佛有所领悟。\n");
		return 1;
	}
	return notify_fail("你要领悟什么？\n");
}

