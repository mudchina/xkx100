// Room: /d/5lt/xiaolu.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条去海滨浴场的小路，路两旁都栽上了村里新引进的亚热带
植物。一阵雨星伴着微带海水气息的风飘了过来，你不禁打了个喷嚏。
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"north"     : __DIR__"haitan",
		"southeast" : __DIR__"wroad4",
	]));

	set("no_clean_up", 0);
	set("coor/x", -195);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
