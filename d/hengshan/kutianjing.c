// Room: /d/hengshan/kutianjing.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "苦甜井");
	set("long", @LONG
北岳庙的右下角，有二井相距不过三尺，而水质一苦一甜，称为“
苦甜井”。甜井中水味清洌甘甜，道家弟子奉为圣水，游人到此，每感
口枯舌燥，饮此水确有消暑清热之益。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"beiyuemiao",
	]));
	set("resource/water", 1);
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 40);
	set("coor/y", 3170);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

