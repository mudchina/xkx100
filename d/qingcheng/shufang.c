// d/qingcheng/shufang.c
inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这是一间干干净净的书房。当中一个大檀木桌，桌上放着不少书籍。
靠墙的地方还有一个书架，架上满满的全是各种封装的书。其中不少书
看上去古意盎然，显然年代已久。
LONG );
	set("exits", ([
		"north" : __DIR__"zoulang2",
	]));
	set("objects", ([
		"/clone/book/laozi1": random(2),
		"/clone/book/laozi13": random(2),
		"/clone/book/daodejing-i": (int)(random(4)/3),
		"/clone/book/daodejing-ii": (int)(random(4)/3),
		"/clone/book/cheng18po": (int)(random(4)/3),
	]) );
	set("coor/x", -8070);
	set("coor/y", -850);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}