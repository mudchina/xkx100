// Room: /d/songshan/shuzhai.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h>
int do_get();

string *book = ({
	"/clone/book/book-silk",
	"/clone/book/book-paper",
	"/clone/book/sword_book1",
	"/clone/book/sword_book4",
	"/clone/book/strike_book",
});

void create()
{
	set("short","书斋");
	set("long",@LONG
这里是嵩山派的书斋，靠墙是一排书架，上面整整齐齐码着一排排
书，大略看去各派武籍都有。南侧靠窗处有张书桌，桌上四宝俱备。
LONG);
	set("exits",([
		"north" : __DIR__"eastting",
	]));
	set("book_count", 2);
	set("coor/x", 0);
	set("coor/y", 890);
	set("coor/z", 90);
	setup();
}
void init()
{
	add_action("do_get", "chou");
	add_action("do_get", "qu");
}
int do_get()
{
	object ob, me=this_player();
	me->add("qi", -5);
	if ((query("book_count") > 0) && (random(5) == 3))
	{
		ob=new(book[random(5)]);
		ob->move(me);
		message_vision(HIY"$N在书架上翻来翻去翻了半天，取下一本"+ob->query("name")+HIY"来。\n"NOR,me);
		add("book_count", -1);
	}
	else 
		message_vision("$N在书架上翻来翻去翻了半天，也不知道在找啥。\n",me);
	return 1;
}
