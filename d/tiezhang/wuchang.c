// Room: /d/tiezhang/wuchang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>

inherit ROOM;
//void init();
//int do_chazhi();

void create()
{
        set("short",HIC"武场"NOR);
	set("long", @LONG
这是一片平地，树着些练功器具。铁掌帮众正在热火朝天地练功。
LONG
	);
        set("exits", ([ 
		"west" : __DIR__"zoulang4",
	]));
	set("objects",([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -2010);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_chazhi", "chazhi");
}


int do_chazhi(string arg)
{       
        mapping fam;
	object me;
        me = this_player();

	if (!living(me)) return 0;
	if ( !living(this_player()) || arg != "huo" )
	{
		write("你想往哪儿插呀！\n");
		return 1;
	}
	if (!(fam = me->query("family")) || fam["family_name"] != "铁掌帮")
		return notify_fail("你非本帮弟子，不能在此练功！\n");

	if ( (int)me->query_skill("strike", 1) > 100)
		return notify_fail("你将双手插入镬中，发现铁沙的温度对你来说太低，已毫无意义了。\n");
 
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write("你觉得一股热气直逼上来，焦燥难当！\n");
		me->unconcious();
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("strike", me->query("int"));
	message_vision("$N将双手插进镬中的铁沙里。\n", me);
	write("灼热的铁沙将你的双手烫得通红，你觉得双手变得强壮有力。\n");
	return 1;
}
