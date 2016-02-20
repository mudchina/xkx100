// Room: /d/lingxiao/book.c
// Last Modified by winder on Jul. 15 2001

inherit ROOM; 
string* books = ({
	BOOK_DIR+"book-bamboo",
	BOOK_DIR+"book-silk",
	BOOK_DIR+"book-stone",
	BOOK_DIR+"book-iron",
});
void create()
{
	set("short","书房");
	set("long",@LONG
这里是白自在的书房，一室之内，放满了各类书籍。白自在虽然狂
妄自大，但说到学问，却当真也是饱读诗书，学富五车。这里的书架，
大大小小，总有十几个吧。白自在的书童正在这为他整理。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east"   : __DIR__"weideju",   
		"south"  : __DIR__"bridge",
	]));
	set("objects", ([  
		__DIR__"npc/su" : 1,  
		BOOK_DIR+"feixue-book" : 1,  
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup(); 
	replace_program(ROOM);
}

