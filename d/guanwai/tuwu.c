// /guanwai/tuwu.c

inherit ROOM;

void create()
{
	set("short", "小土屋");
	set("long", @LONG
这是一座用黄土垒成的小屋，屋内打扫的很干净。四周的墙壁上挂
满了各种棍子，钎子，开山斧，小锯子等工具，看来似乎是采参所用的
工具。屋内西面的火炕上坐着一位上了年纪的老人，正在吸着旱烟袋。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaoxiang",
	]));
	set("objects", ([
		__DIR__"npc/heersu" : 1,
	]));
	set("coor/x", 6030);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}