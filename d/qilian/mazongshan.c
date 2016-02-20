// Room: /d/qilian/mazongshan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "马鬃山");
	set("long", @LONG
马鬃山状如其名，山脉绵长，山峰岑差不齐，挽似野马之鬃。听老
人们讲，凡心诚而善入山者，可得宝藏而归，但凡为富不仁进山者，必
难生还。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"southdown" : __DIR__"niaojutai",
		"west"      : __DIR__"qilianshan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -11000);
	set("coor/y", 3000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}