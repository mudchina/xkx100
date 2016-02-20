// Room: /d/5lt/fanshudi.c

inherit ROOM;

void create()
{
	set("short", "番薯地");
	set("long", @LONG
这是一块番薯地，满目翠绿，长势十分旺盛。
LONG );
	set("exits", ([
		"westup"    : __DIR__"fenghuanglin",
		"southeast" : __DIR__"caodi",
		"northwest" : __DIR__"caomeidi",

	]));
        set("objects", ([
	]));
	set("coor/x", -125);
	set("coor/y", 15);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}