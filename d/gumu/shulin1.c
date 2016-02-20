// shulin1.c 树林
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
这是一片小树林，周围的树木都很高。间杂着一些叫不出名字的鲜
花，五彩缤纷。你隐隐地有些担心起来：不会迷路了吧，转头间却看见
东南边似乎有一条小路，隐藏在树丛之中。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"northdown" : __DIR__"shulin0",
		"southwest" : __DIR__"shulin2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 70);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
