// Room: /d/gaibang/underdl.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "大和街边");
	set("long", @LONG
这是大理城中大和街边上的大树洞。里面破破烂烂的，丢满了各种
杂物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG );
	set("exits", ([
		"out"       : "/d/dali/dahejieeast",
		"northeast" : __DIR__"dlandao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -39900);
	set("coor/y", -71030);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}