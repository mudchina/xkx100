// Room: /d/quanzhou/liangcang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "粮仓");
	set("long", @LONG
粮仓是所占地宽广的库房，堆放着堆积如山的军粮，逢到旱涝灾年
也做济灾之用。由于仓广人少，经常引起匪徒的窥视。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"northeast" : __DIR__"micangxiang",
		"south"     : __DIR__"eastroad1",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1860);
	set("coor/y", -6520);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northeast" && objectp(present("wu jiang", environment(me))))
		return notify_fail("武将大喝道：都督有令，闲杂人等不能由此经过！\n");
	return ::valid_leave(me, dir);
}

