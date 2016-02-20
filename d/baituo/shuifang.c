// Room: /d/baituo/shuifang.c
// Last Modified by Winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "睡房");
	set("long", @LONG
这间睡房宽敞明亮，想来便是庄主的卧室了。有一张书桌，桌子上
放有几本书，却是《易经》之类。墙边有一大箱子。整个房间看上去极
为单调。
LONG);
	set("no_fight", "1");
	set("objects", ([
		BOOK_DIR"bt_book5" : 1,
		BOOK_DIR"bt_book1" : 1,
	]));
	set("book_count",1);
	set("exits", ([
		"west" : __DIR__"tangwu",
	]));
	set("coor/x", -50000);
	set("coor/y", 20052);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	object book, me = this_player();

	if (random(me->query("kar")) > 20 && query("book_count") >= 1)
	{
		write("你走进屋里，随手在床边一翻，忽然发现床单下盖着什么东西。\n");
		write("掀开床单一看，原来是一本薄薄的线装书。\n");
		book = new("/clone/book/bt_book");
		book->move(environment(me));
	}
	add("book_count", -1);
}
