// /d/shenlong/xiaowu.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit ROOM;
string* books = ({
	"/clone/book/book-bamboo",
	"/clone/book/book-paper",
	"/clone/book/book-stone",
	"/clone/book/book-iron",
//	"/d/shenlong/obj/shoufa",
//	"/d/shenlong/obj/bufa",
});


void create()
{
	set("short", "小屋");
	set("long", @LONG
一进小屋，只见墙上挂满了无数名贵的字画。书架上也堆满了平时
难得一见的各种各样的书籍。一个相貌英武的中年文士正对着一幅字画
唉声叹气。
LONG );

	set("exits", ([
		"south" : __DIR__"caodi",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/lu": 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
	]));
	set("outdoors", "shenlong");
	set("coor/x", 4000);
	set("coor/y", 3050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}

