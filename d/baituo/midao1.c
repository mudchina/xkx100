// Room: /d/baituo/midao1.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"秘道"NOR);
	set("long", @LONG
这条阴暗的秘道在山腹中曲折延伸，不知通往何处。这里的石壁非
常潮湿，看来附近有水源。
LONG);
	set("objects", ([
		__DIR__"npc/hama" : 1,
	]));
	set("exits", ([
		"westdown" : __DIR__"midao2",
		"east"     : __DIR__"midao0",
	]));
	set("coor/x", -49930);
	set("coor/y", 20080);
	set("coor/z", 10);
	setup(); 
}

void init()
{
	object me = this_player();
	if (random(me->query("kar")) <8 && me->query_con() < 30)
	{ 
		tell_object(me, HIB"你忽然感到呼吸一紧，原来是这里的空气污浊、流通不畅。\n" NOR );
		tell_room(environment(me),me->name()+"突然脸色变得极为难看，并深深地吸了口气。\n" NOR, ({ me }));
		me->add("neili", -50);
		me->receive_wound("qi", 10);
		me->receive_wound("jing", 20);
	}
}
