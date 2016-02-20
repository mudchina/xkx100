// /yubifeng/eastroom2.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "东厢房");
	set("long", @long
东厢房原是杜庄主款待宾客的所在，床帐、屏风、几桌、一应起居
之具齐备，陈设得甚是考究。	
long );
	set("exits", ([
		"west" : __DIR__"zoulang6",
	]));
	set("objects", ([
		__DIR__"npc/miaoruolan" : 1,
		__DIR__"npc/qiner" : 1,
	]));
	set("coor/x", 6140);
	set("coor/y", 5200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
