// /d/taohuacun/road2.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set("short","田间小路");
	set("long", @LONG
这是乡下田间南北走向的一条小路，弯弯曲曲的伸向前方。路的两
边是以前乡民们种菜的地方。
LONG
);
	set("exits", ([
		"north" : __DIR__"road3",
		"south" : __DIR__"road1",
		"east"  : __DIR__"caidi4",
		"west"  : __DIR__"caidi3",
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}