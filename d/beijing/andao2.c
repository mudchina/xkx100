// /d/beijing/andao2.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "天地会暗道");
	set("long", @LONG
一走进黑漆漆的地道，阵阵阴风从北边吹来，你感到有些冷。两边
都是土墙，隐约可以听到上面脚底落地的声音。
LONG );
	set("exits", ([
		"north" : __DIR__"andao4",
		"south" : __DIR__"andao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -212);
	set("coor/y", 4010);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
