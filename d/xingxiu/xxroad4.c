// Room: /d/xingxiu/xxroad4.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条在山壁上人工开凿出来崎岖的小路上，这里寒风凛冽，
西面是望不见底的深涧。
LONG );
	set("exits", ([
		"southdown" : __DIR__"tianroad3",
		"north" : __DIR__"xxroad5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -51000);
	set("coor/y", 20110);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
