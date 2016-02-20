// Room: /d/baituo/midao2.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"秘道"NOR);
	set("long", @LONG
这条阴暗的秘道在山腹中曲折延伸，不知通往何处。这里的石壁非
常潮湿，看来附近有水源。从这里开始迷道分成了左右两边，往右走好
象可以看见一点亮光。
LONG);		
	set("exits", ([
		"westdown" : __DIR__"midao3",
		"eastdown" : __DIR__"midao5",
		"eastup"   : __DIR__"midao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49940);
	set("coor/y", 20080);
	set("coor/z", 0);
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
