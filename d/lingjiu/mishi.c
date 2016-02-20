// mishi.c
//
inherit ROOM;

void create()
{
    set("short", "密室");
	set("long", @LONG
这是个阴暗的密室，墙上的油灯发出昏暗的黄光。
LONG );
	set("exits", ([
		"up" : __DIR__"huayuan",
	]));
	set("objects",([
		"/clone/book/zhemei_book1" : 1,
		"/clone/book/zhemei_book2" : 1,
		"/clone/book/liuyang_book1" : 1,
		"/clone/book/liuyang_book2" : 1,
		"/clone/book/qijianpu" : 1,
	]));
	set("coor/x", -50900);
	set("coor/y", 30190);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
	me=this_player();
	if ((dir=="up") &&
		(!present("zhangfa tu1", this_object())) ||
		(!present("zhangfa tu2", this_object())) ||
		(!present("shoufa tu1", this_object())) ||
		(!present("shoufa tu2", this_object())) ||
		(!present("pu", this_object())) )
			return notify_fail("这的秘辑不见了你怎能就走呢！\n");

	return ::valid_leave(me, dir);
}