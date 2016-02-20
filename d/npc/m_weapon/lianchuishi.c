// ROOM lianchuishi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "打锤坪");
	set("long", @LONG
这里是玄兵古洞的打造钢锤的地方。处在荒芜人烟的大雪山上。大
雪山长年积雪，这里却是一坪长草扶地的山谷。四周摆了很多铜铁五金，
一个腼腆少年手执大锤，看着你走近身来。
LONG );
	set("exits", ([
		"eastdown" : "/d/xuedao/nroad5",
	]));
	set("objects", ([
		__DIR__"npc/shichui" :1,
	]));
	set("coor/x", -30050);
	set("coor/y", -8000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
