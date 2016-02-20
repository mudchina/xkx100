// Room: /d/chengdu/xiaoxiang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
这里是西门边上一条幽深的小巷，不知道通向那里。这里不时地有
本地居民走过，你也许可以向他们打打听听。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"south"     : __DIR__"xijie",
		"northeast" : __DIR__"path1",
	]));

	set("coor/x", -8080);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

