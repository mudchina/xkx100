// xiaodao5.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条从南到北的林间小道，沿途风景极之清幽，参天古树，拔
地而起，两旁百花争艳。令人留连忘返。
LONG );
	set("exits", ([
		"south" : __DIR__"muwu1",
		"north" : __DIR__"qingcaop",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xiaoyao");
	set("coor/x", 80);
	set("coor/y", -510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}