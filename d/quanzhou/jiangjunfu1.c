// Room: /d/quanzhou/jiangjunfu1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "将军府书房");
	set("long", @LONG
这是靖海侯府的书房，里面除了书籍之外，更多的还是各种兵刃。
LONG );
	set("exits", ([
		"south" : __DIR__"jiangjunfu",
	]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

