// Room: /heizhao/hetang.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "荷塘");
	set("long", @LONG
高山上有这样的荷塘，本就希罕，塘中更茂然长满红红白白的
荷花。塘边堤岸上种了不少棕榈树，在山风中伸展摇晃着，哗啦作
响。塘中污泥约有三尺来深，荷塘正中一条小石桥通往对面。
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"shiliang3",
		"north"  : __DIR__"shiqiao",
	]));
	set("coor/x", -5020);
	set("coor/y", -1220);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}