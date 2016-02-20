// shulin3.c 树林
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
这里是树林的边缘，参天古树已经很稀少了。东面有一座高山，隐
约看见山间云雾缭绕中，似乎有什么廊檐的建筑。山势缓和，但山上郁
郁葱葱地栽满了树木。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"south"     : __DIR__"caodi",
		"northeast" : __DIR__"shulin2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3220);
	set("coor/y", 50);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
