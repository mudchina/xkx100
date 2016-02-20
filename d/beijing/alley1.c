// /d/beijing/alley1.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "杨柳胡同");
	set("long", @LONG
你走在巷道上，感到似乎有些不妙。南边仍是空荡荡的小道，见不
到几个行人。东边是一家面馆。北边是西长安大道。一股阴风吹来，你
禁不住打了个寒颤。 
LONG );
	set("outdoors", "beijing");

	set("exits", ([
		"east" : __DIR__"mianguan",
		"south" : __DIR__"alley2",
		"north" : __DIR__"xichang2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
