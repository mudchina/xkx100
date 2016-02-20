// Room: /city/qinshi.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "琴室");
	set("long", @LONG
室内两后壁，各装一堂透空雕花罩格，贴墙放琴几，几上放置盆景。
两侧布置一式雕花海梅方桌，围以团凳。南，北，东三面墙壁，安放红
木雕花几座，间以瓷凳。一室明净，一尘不染。琴室前有廊庑一架，临
水栏槛。槛外疏柳，横卧水际；水面微波，倒影摇曳。
LONG );
	set("exits", ([
		"southeast" : __DIR__"luqiao",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -25);
	set("coor/y", 5);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

