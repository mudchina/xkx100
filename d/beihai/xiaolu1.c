// /d/beihai/xiaolu1.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条沿着湖的小路，路西边是一片松树林，东面可以看见琼岛
上的白塔。松树林里不时可以看见一只只松鼠跳来跳去。
LONG
	);
	set("exits", ([
		"south" : __DIR__"ximen",
		"north" : __DIR__"xiaolu2",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
