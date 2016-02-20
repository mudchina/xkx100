//room: qinyun.c

inherit ROOM;

void create()
{
	set("short","琴韵小筑");
	set("long",@LONG
这是一间小巧玲珑的房舍，颇为精雅。周围稀稀落落的四五间小房
屋，建造在一个不知是小岛还是半岛上。这里是慕容世家丫鬟阿碧的住
所。
LONG );
	set("exits",([
		"westdown" : __DIR__"muti",
		"east"     : __DIR__"xiaoting",
		"south"    : __DIR__"neitang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1500);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}