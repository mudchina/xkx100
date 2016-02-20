// Room: /d/baituo/zhulin.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","竹林");
	set("long", @LONG
这里是青竹林，常有蛇出没。南边是蒿草丛。北边有一个大岩洞。
LONG	);
	set("exits",([
		"northup" : __DIR__"cave",
		"south"   : __DIR__"cao2",
	]));
	set("objects",([
		__DIR__"npc/qingshe" : random(2),
		__DIR__"npc/snake" : random(3),
	]));
	set("coor/x", -50040);
	set("coor/y", 20060);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
