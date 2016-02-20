// midao4.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
台阶终于走到了头，眼前是一间小小的石室，周围墙壁上插着几盏
油灯，照得石室里一片昏黄。北边有一条通道。
LONG );
	set("exits", ([
		"westup" : __DIR__"midao3",
		"north": __DIR__"midao5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50900);
	set("coor/y", 30170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}