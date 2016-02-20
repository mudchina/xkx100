// Room: /d/wuxi/road2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "东驿道");
	set("long", @LONG
这是苏州和无锡之间的大驿道，这两座江南名城相隔得是如此之
近。使得不少做生意的商贩都早晚往返于两城之间也不觉得麻烦。因
路上的人也就特别得多。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"road3",
		"west"  : __DIR__"road1",
	]));
	set("coor/x", 600);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}