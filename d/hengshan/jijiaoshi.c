// Room: /d/hengshan/jijiaoshi.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "鸡叫石");
	set("long", @LONG
北岳庙的西侧，有一尺许见方的石头，称鸡叫石。击之，“咯咯”
作鸡鸣声，故名。清晨敲击，引起山谷回声，如群鸡争鸣，就称“金鸡
报晓”。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"beiyuemiao",
	]));
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 3170);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

