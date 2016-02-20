// /d/shenlong/luanshi.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "乱石");
	set("long", @LONG
这儿是乱石堆，似乎不是天然而成。一阵海风吹来，你打了一个哆
嗦，不禁害怕起来，但细想一下不知其所以然。
LONG
	);

	set("outdoors", "shenlong");
	set("exits", ([
	      "southup"   : __DIR__"houshan",
	      "northeast" : __DIR__"jushi",
	]));

	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me = this_player();
	int damage;

	if( interactive(me = this_player()) &&
		!(me->query("sg/spy") ||
		me->query("family/family_name") == "神龙教") &&
		random((int)me->query_skill("dodge")) < 80 )
	{
		message_vision( HIR "$N的眼前突然出现一个无底的深渊...$N掉入了陷阱之中。\n" NOR, me);
		message_vision( HIR"陷阱中的钢板突然冒出许多锋利的钢针，深深地扎进$N的身体中...\n" NOR, me);
		damage = 100000 / ( 100 + (int)me->query_skill("force"));
		me->receive_wound("qi", damage + random(damage), "被扎死了");
		me->receive_damage("qi", damage + random(damage), "被扎死了");

		me->apply_condition("snake_poison", 50 + random(50) + me->query_condition("snake_poison"));
	}
}

