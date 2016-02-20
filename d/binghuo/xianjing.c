// Room: /binghuo/xianjing.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "陷阱");
	set("long", @LONG
深坑底窄口广，深达五丈，坑底周围插上削尖的木棒。更在坑边
堆了不少大石，只待人落入坑中，便可投石砸打。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"up"   : __DIR__"inhole1",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (random((int)me->query_skill("dodge")) <= 20)
	{
		me->receive_wound("qi",30);
		return notify_fail("你使劲儿一蹦，离顶还有数丈远就掉了下来，摔的鼻青脸肿。\n");
	}
	if (random((int)me->query_skill("dodge")) <= 35) 
	{
		me->receive_wound("qi",20);
		return notify_fail("你奋力一跃，却离顶还有一丈多远，看来是白费力气。\n");
	}
	if (random((int)me->query_skill("dodge")) <= 60)
	{
		me->receive_wound("qi",10);
		return notify_fail("你纵身而起，离顶只差一点点了，再加把劲。\n");
	}

	return ::valid_leave(me, dir);
}


