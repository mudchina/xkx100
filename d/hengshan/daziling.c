// Room: /d/hengshan/daziling.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "大字岭");
	set("long", @LONG
大字岭是入恒山必由之路。石壁上镌有 "恒宗" 二字，高可两丈，
笔力遒劲，气势雄浑。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"west"      : __DIR__"yunge",
		"northeast" : __DIR__"hufengkou",
	]));
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 3140);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

