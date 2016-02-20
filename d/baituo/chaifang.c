// Room: /d/baituo/caifang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","柴房");
	set("long", @LONG
这是间不宽的柴房，木柴已经快烧光了，墙角放着几把『柴刀』。
LONG );
	set("exits",([
		"west" : __DIR__"chufang",
	]));
	set("objects",([
		__DIR__"npc/laocai" : 1,
	]));
	set("coor/x", -49990);
	set("coor/y", 20060);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
