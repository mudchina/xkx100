// Room: /yangzhou/tianningshuju.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","天宁书局");
	set("long",@LONG
这里专卖市坊中各种字画和书籍刻本，其中还有不少是难得一见的
珍本，但由于老板不善经营，加上地方过于偏僻，所以每天买书，看书
的人没有多少，店内光线有些不足，只有老板辛友清一人无精打采地守
着，四周书架(shelf) 乱七八糟堆着一些卷轴，线订本，给人一种杂乱
无章的感觉。
LONG );
	set("exits", ([
		"southeast"  : __DIR__"tianningxiang",
	]));
	set("objects", ([
		__DIR__"npc/bookboss" : 1,
	]));
	set("item_desc", ([
		"shelf"  : "书架上堆满了书，有些已经翻得破破烂烂。\n",
	]));
	set("coor/x", 30);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}