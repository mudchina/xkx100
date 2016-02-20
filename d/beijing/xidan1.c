inherit ROOM;

void create()
{
	set("short", "西单北大街");
	set("long", @LONG
这里是西单北大街。东边有一家很大的赌场，里面闹哄哄的。北边
是西四北大街。南边就是西单了。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"north" : __DIR__"xisi",
		"south" : __DIR__"xidan",
		"east"  : __DIR__"duchang",
		"west"  : __DIR__"hai_men",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
