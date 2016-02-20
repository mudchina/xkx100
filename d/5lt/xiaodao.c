// Room: /d/5lt/xiaodao.c

inherit ROOM;

void create()
{
	set("short", "乡间小道");
	set("long", @LONG
这是条坑坑洼洼的乡间小道，路两旁都栽上了村里新引进的亚热带
植物。往前走就到电视台了。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"north"     : __DIR__"mubanlu",
		"southeast" : __DIR__"wroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -185);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
