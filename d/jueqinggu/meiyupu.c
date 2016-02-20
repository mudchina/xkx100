// Room: /d/jueqinggu/meiyupu.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "梅雨瀑");
	set("long", @LONG
这道瀑布从危崖峭壁顶上悬挂直下，出瀑口不远遇一横突岩石，激
石飞溅，化作毛毛细雨，类似五、六月梅雨，故名梅雨瀑。
LONG
	);
	set("exits", ([
		"west" : __DIR__"guanlanting", 
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -470);
	set("coor/y", -380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

