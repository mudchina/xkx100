// Room: /d/gaibang/underwd.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "土匪窝边");
	set("long", @LONG
这是武当山下土匪窝边上的小山洞。里面破破烂烂的，丢满了各种
杂物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG );
	set("exits", ([
		"out"       : "/d/wudang/tufeiwo1",
		"northeast" : __DIR__"wdandao2",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/li-sh" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -2000);
	set("coor/y", -810);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}