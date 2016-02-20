// Room: /d/baituo/cao2.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","草丛");
	set("long", @LONG
这里是乱草丛。北边是青竹林。其余三面都是齐腰高的蒿草，常
有蛇出没。
LONG	);
	set("exits",([
		"west"  : __FILE__,
		"north" :__DIR__"zhulin",
		"east"  : __DIR__"cao1",
		"south" : __DIR__"cao1",
	]));
	set("objects",([
		__DIR__"npc/qingshe" : random(2),
		__DIR__"npc/jinshe" : random(2),
		__DIR__"npc/snake" : random(2),
	]));
	set("outdoors","baituo");
	set("coor/x", -50040);
	set("coor/y", 20050);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
