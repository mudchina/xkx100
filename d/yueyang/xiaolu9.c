// Room: /d/yueyang/xiaolu9.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这是通往酒香山上酒香亭的黄土小道。小道两边茶树连绵，竹响随
人，真是个清幽所在。望山下，洞庭湖水簇拥君山，青碧一片，景色甚
是怡人。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"westdown" : __DIR__"yangeng1",
		"eastup"   : __DIR__"jiuxiangting",
	]));
	set("coor/x", -1790);
	set("coor/y", 2280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
