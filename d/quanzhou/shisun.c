// Room: /d/quanzhou/shisun.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石笋");
	set("long", @LONG
这是泉州西面的一处地貌奇观，经千年风蚀形成的石笋千奇百怪，
似剑、似刀、似锥，形态各异。洞壑纵横，不知所终。南面的山谷中有
一所草庵。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"shangu",
		"north" : __DIR__"luanshigang",
	]));
	set("coor/x", 1820);
	set("coor/y", -6590);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
