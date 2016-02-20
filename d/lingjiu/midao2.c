// midao2.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你的眼前是一条用汉白玉铺成的台阶，一直向下延伸，两边的墙壁
都是花岗岩，墙上隔十来步就有一盏油灯，使你能看清周围。
LONG );
	set("exits", ([
		"southup" : __DIR__"midao1",
		"northdown": __DIR__"midao3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30160);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}