// Room: /huanghe/weifen.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "渭汾流域");
	set("long", @LONG
汾河和渭河汇入黄河，增大了其水势，也带来了更多的泥沙。这里
河东是晋，河西是陕。
LONG );
	set("exits", ([
		"south" : __DIR__"huanghe1",
		"north" : __DIR__"huanghe_1",
		"southwest" : __DIR__"road5",
		"northeast" : __DIR__"dukou2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("coor/x", -1000);
	set("coor/y", 700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}