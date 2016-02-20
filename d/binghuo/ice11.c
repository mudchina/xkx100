// Room: /binghuo/ice11.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "冰海");
	set("long", @LONG
冰上甚是滑溜，你右足稍稍一沾，扑通一声，摔入了海中。寒冷
的冰水冻得你全身僵直，好在离那火柱已很近了。那火柱乃北极附近
的一座活火山，火焰喷射，烧得山旁海水暖了。
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"northup" : __DIR__"haitan",
	]));
	set("objects", ([
		__DIR__"npc/shayu" : 2,
	]));
	setup();
	replace_program(ROOM);
}

