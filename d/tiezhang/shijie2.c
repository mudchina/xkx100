// Room: /d/tiezhang/shijie2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
一排石阶盘旋而下，消失在浓浓的黑暗中。石阶上长满的绿色的青
苔，滑不留脚。远处黑暗的尽头似乎有点昏黄的光亮。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"westup"    : __DIR__"shijie1",
		"northdown" : __DIR__"shijie3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", 1860);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

