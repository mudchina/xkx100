// Room: /d/gaibang/underwx.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "草堆下面");
	set("long", @LONG
这是无锡城外杏子林丐帮大义分舵草堆的洞里。四周丢满了各种杂
物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG );
	set("exits", ([
		"out"   : "/d/wuxi/dayifenduo",
		"south" : __DIR__"wxandao2",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/xie" : 1,
	]));
	set("coor/x", 400);
	set("coor/y", -740);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
