// wdroad3.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，四周静悄悄的。
LONG );
	set("outdoors", "sanbuguan");
	set("exits", ([
		"south" : __DIR__"wdroad4",
		"north" : __DIR__"wdroad2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
 