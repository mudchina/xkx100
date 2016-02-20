// Room: /d/huashan/jzroad6.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "树林外");
	set("long", @LONG
树林外，赫然站着一个汉子，在阴森森的林子边上，凭添一股煞气。
西上是登山的路，东边就进入森林了。
LONG );
	set("outdoors", "zhongtiao");
	set("exits", ([ /* sizeof() == 4 */
	    "enter"   : __DIR__"jzroad5",
	    "westup"  : __DIR__"jzroad7",
	]));
	set("objects", ([
	     CLASS_D("huashan") + "/cheng-buyou": 1,
	]));

	set("coor/x", -920);
	set("coor/y", 190);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
