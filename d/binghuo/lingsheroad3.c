// Room: /binghuo/lingsheroad3.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在树林中的小路上，四周僻静得让你感到窒息般的异常。密
密层层的树林遮天蔽日，你甚至听不到一点虫鸣。山顶有座小屋岛。
LONG );
	set("outdoors", "lingshe");
	set("no_clean_up", 0);
	set("exits", ([
		"westdown"  : __DIR__"lingsheroad2",
		"northup"   : __DIR__"lingshetop",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (random(2) == 1)
	{
		me->receive_damage("qi", 10);
tell_object(me, HIR"忽然一阵刺痛，"NOR"你一脚踩在钢针上了，不禁破口大骂：
“他妈的！哪个王八蛋干的？！”\n");
	}
        return ::valid_leave(me, dir);
}

