// Room: /d/tiezhang/hhyuan1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "后花园");
	set("long", @LONG
这是一处环境优雅的花园。只见乔松修竹，苍翠蔽天，层峦奇岫，
静窈幽深。西面有一座假山，东面是一大片的花圃。北面是通往山上的
路。
LONG	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"shanlu3",
		"south" : __DIR__"hxfang",
		"east"  : __DIR__"hhyuan2",
		"west"  : __DIR__"hhyuan3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1940);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}