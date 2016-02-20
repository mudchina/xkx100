// Room: /d/yueyang/xiangchunting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "香椿亭");
	set("long", @LONG
香炉山上，有雕龙石柱，六角锷顶石亭。名曰香椿亭。前有青石大
香炉一个，亭炉相应，境与意会。山下是天然的避风港，宋代杨么的英
雄豪杰在此结义，振虎帐之师，立鸦咀之战船，建水军之点将台，操练
战船，风雪滚滚，轮橹依依，万古东南多壮观，百年豪杰几登临。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"xianglushan",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/fang" : 1,
	]));
	set("coor/x", -1800);
	set("coor/y", 2250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
