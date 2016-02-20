// Room: /city/biaojudy.c

inherit ROOM;

void create()
{
	set("short", "大院");
	set("long", @LONG
大院里显得有些凌乱，趟子手和镖师们进进出出，似乎都在满地里
忙碌着什么。一棵很大的榕树栽在院子中央，给火辣辣的福州带来一点
凉爽。
LONG );
	set("exits", ([
		"out"   : __DIR__"biaoju",
		"north" : __DIR__"biaojuzt",
		"east"  : __DIR__"biaojuhc",
		"west"  : __DIR__"biaojucyf",
	]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1830);
	set("coor/y", -6298);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
