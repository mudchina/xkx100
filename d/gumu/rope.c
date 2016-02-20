// rope.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "绳床");
	set("long", @LONG
一条挂在侧厢中的细麻绳。
LONG );
	set("no_clean_up", 0);
	set("coor/x", -3180);
	set("coor/y", -40);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

