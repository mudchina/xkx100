// Room: /d/tiezhang/shanjiao.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "山脚下");
	set("long", @LONG
这里已到了山脚下，此处近看，但见五座山峰峭兀突怒，确似五根
手指竖立在半空之中。居中一峰尤见挺拔，笔立指天，耸入云表，下临深
涧。山侧生着一片松林，松梢留雪，树身尽皆向南弯曲，想见北风极烈。
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
		"northup"   : __DIR__"shanmen",
		"southeast" : __DIR__"road3",
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -2040);
	set("coor/y", -2010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
