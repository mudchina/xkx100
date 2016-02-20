// Room: /d/quanzhou/tudimiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "土地庙");
	set("long", @LONG
这是一间十分破旧的土地庙，也不知荒废了多久，梁上地下布满了
灰尘。土地神像後面的墙上有个洞口，老鼠爬进爬出，恶心极了。
LONG );
	set("exits", ([
		"west"   : __DIR__"luoyangqiao",
	]));
	set("objects", ([
		"/d/village/npc/dipi" : 1,
	]));
	set("coor/x", 1900);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
