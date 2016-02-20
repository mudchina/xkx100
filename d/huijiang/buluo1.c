// Room: /d/huijiang/buluo1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "回部部落");
	set("long", @LONG
此处三面是树林，一面斜坡直连到大草原。你现在处身在几个大帐
篷之间，东边的一个帐篷看来特别的大一点。南边有条小路通向树林之
中。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"zhangpeng",
		"west"  : __DIR__"zhangpeng1",
		"north" : __DIR__"buluo2",
		"south" : __DIR__"buluo",
	]));
	set("objects", ([ /* sizeof() == 4 */
		CLASS_D("honghua")+"/zhang-jin" : 1,
	]));
	set("outdoors", "huijiang");
	set("coor/x", -50050);
	set("coor/y", 9050);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
