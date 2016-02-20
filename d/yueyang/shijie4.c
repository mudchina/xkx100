// Room: /d/yueyang/shijie4.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "青石道");
	set("long", @LONG
这是通往酒香山上酒香亭的青石小道。小道两边茶树连绵，竹响随
人，真是个清幽所在。望山下，洞庭湖水簇拥君山，青碧一片，景色甚
是怡人。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"shijie3",
		"westup"   : __DIR__"shijie5",
	]));
	set("coor/x", -1760);
	set("coor/y", 2280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
