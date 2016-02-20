// Room: /d/suzhou/gumujiaohe.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "古木交诃");
	set("long", @LONG
古木交诃在荷花厅的西面，一排不同图案的漏窗，使你透过漏窗隐
隐看到中部的水光山色和高低错落的楼阁，此处赏景，有“移步幻影”
之妙。穿过西窗孔望去，可以遥望绿荫轩、明瑟楼，给人一种“庭院深
深深几许”和空间不尽之感。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"hehuating",
		"southwest" : __DIR__"chitang",
	]));
	set("coor/x", 820);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
