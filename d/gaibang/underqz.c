// Room: /d/gaibang/underqz.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "铁枪庙下");
	set("long", @LONG
这是嘉兴铁枪庙下的小洞。里面破破烂烂的，丢满了各种杂物，还
有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG );
	set("exits", ([
		"out"       : "/d/jiaxing/tieqiang",
		"northwest" : __DIR__"qzandao2",
	]));
	set("objects",([
//		CLASS_D("gaibang") + "/li-sh" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", 1510);
	set("coor/y", -1010);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}