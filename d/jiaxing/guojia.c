// Room: /d/jiaxing/guojia.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "郭家民房");
	set("long", @LONG
这是一座废弃已久的民房，家具摆设一应俱全，只是都附着一层灰
土。屋子中间是一张小桌，桌上的杯碗还都没有撤去，看来主人去的很
匆忙。
LONG
	);
	set("exits", ([
		"south" : __DIR__"njroad2",
	]));
	set("no_clean_up", 0);

	set("coor/x", 1570);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}