// Room: /d/baituo/cao1.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","草丛");
	set("long", @LONG
这里是乱草丛。东边是扇拱月形小敞门。其余三面都是齐腰高的蒿
草，常有蛇出没。
LONG	);
	set("exits",([
		"west"  : __FILE__,
		"north" : __DIR__"cao2",
		"east"  : __DIR__"ximen",
		"south" : __FILE__,
	]));
	set("objects",([
		__DIR__"npc/jinshe" : random(2),
		__DIR__"npc/snake" : random(2),
	]));
	set("outdoors","baituo");
	set("coor/x", -50040);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}


