// Room: /d/wuyi/tianxinyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "天心岩");
	set("long", @LONG
天心岩在武夷山北部。《武夷山志》载：「全山百二十里度之，是
峰居中央，犹天之枢极也，故曰天心。」
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"yonglechansi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1410);
	set("coor/y", -4930);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

