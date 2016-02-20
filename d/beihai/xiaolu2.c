// /d/beihai/xiaolu2.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条沿着湖的小路，路西边是一片松树林，上的白塔。松树林
里不时可以看见一只只松鼠跳来跳去。东面隐隐可以看见一个亭子的一
角。
LONG
	);
	set("exits", ([
		"east"      : __DIR__"wulong",
		"south"     : __DIR__"xiaolu1",
		"northeast" : __DIR__"dukou1",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
