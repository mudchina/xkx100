// kongdi.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
这是终南山山腰处的一块空地，地势平坦。北面一条小路直攀山璧
而上，通往是终南山主峰。南边和西边一大片密林，只闻阵阵琴声自林
中传出。往北是一条山路。往南和西各有一条小径。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"west"    : __DIR__"shulin5",
		"south"   : __DIR__"shulin4",
		"northup" : __DIR__"shanlu1",
	]));
	set("coor/x", -3200);
	set("coor/y", 90);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
