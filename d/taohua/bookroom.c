// Room: /d/taohua/bookroom.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	int i,b1,b2,b3;
	string temp;
	object y1,y2,y3;
	set("short", "书房");
	set("long", @LONG
这里是黄药师读书的地方。窗明几净，一尘不染。一张古意盎然的
书案放在房间正中，案上摆着几本翻开了的线装书籍。靠墙的地方还有
一个书架，架上满满的全是各种封装的书。其中不少书看上去古意盎然，
显然年代已久。
LONG
	);
	set("exits", ([
		"west" : __DIR__"zoulang4",
	]));
	set("objects", ([
//		"/clone/book/yijing"+random(4) : 1,
//		"/clone/book/yijing"+random(4) : 1,
//		"/clone/book/bagua"+random(2)  : 1,
	]));
	set("coor/x", 9030);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	b1 = random(4);
	temp = "/clone/book/yijing" + b1;
	y1 = new(temp);
	if (y1->violate_unique())	destruct(y1);
	else 	y1 ->move(this_object());
	b2 = random(4);
	temp = "/clone/book/yijing" + b2;
	y2 = new(temp);
	if (y2->violate_unique())	destruct(y2);
	else 	y2 ->move(this_object());
	b3 = random(2);
	temp = "/clone/book/bagua" + b3;
	y3 = new (temp);
	if (y3->violate_unique())	destruct(y3);
	else 	y3 ->move(this_object());
	replace_program(ROOM);
}