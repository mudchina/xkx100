// Room: /d/wuxi/eastroad2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "东林路");
	set("long", @LONG
东林路是通向无锡东门外的一条大街，这条街没有什么河道穿过，
路面十分宽阔平整。西边是衙门口，那里的人不多。北边传来一阵阵朗
朗的读书声。南边是打铁铺，叮叮当当的声音老远就能听到。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"shuyuangate",
		"south" : __DIR__"datiepu",
		"east"  : __DIR__"eastgate",
		"west"  : __DIR__"eastroad1",
	]));
	set("objects", ([
		__DIR__"npc/polan" : 1,
	]));
	set("coor/x", 390);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}