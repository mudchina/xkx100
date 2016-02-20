// Room: /d/jueqinggu/dufengling.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "独峰岭");
	set("long", @LONG
这里两边山峰壁立，抬头望天，只余一线。山青水碧，景色极尽清
幽，只是四下寂无声息，隐隐透著凶险，溪心有九块大石迎面耸立，犹
如屏风一般，挡住了去路。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"guanlanting",
		"southdown" : "/d/xiangyang/caodi1",
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -390);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

