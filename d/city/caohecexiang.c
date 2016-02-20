// Room: /yangzhou/caohecexiang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","小草河侧巷");
	set("long",@LONG
傍依官河的草河小街上的一处普普通通的巷子，也是这里的居民区
的一部分。向东穿过草河小街就是官河了，西南通向繁华热闹的通泗街，
从那里向西就是通泗门－扬州的西门。这里虽小，却热热闹闹，两侧有
许多店铺，另有许多小贩沿街摆摊，吆喝着自己的生意。
LONG );
	set("outdoors", "yangzhouw");
	set("exits", ([
		"east"      : __DIR__"yudian",
		"southeast" : __DIR__"huadian",
		"southwest" : __DIR__"garments",
		"north"     : __DIR__"caizhu",
		"northeast" : __DIR__"tongsijie",
	]));
	set("objects", ([
		__DIR__"npc/tangfan" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}