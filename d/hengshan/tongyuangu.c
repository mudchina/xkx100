// Room: /d/hengshan/tongyuangu.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "通元谷");
	set("long", @LONG
通元谷孤处见性峰下，相传为张果老成仙前修道之所，由于他道号
“通元”，这里也就成了通元谷。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"eastup"  : __DIR__"guolaoling",
	]));
	set("objects", ([
		"/clone/medicine/vegetable/chuanbei" : random(2),
	]));
	set("outdoors", "hengshan");
	set("coor/x", 20);
	set("coor/y", 3160);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}

