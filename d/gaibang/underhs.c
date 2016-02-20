// Room: /d/gaibang/underhs.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "舍身崖下");
	set("long", @LONG
这是华山舍身崖下的小山洞，里面破破烂烂的，丢满了各种杂
物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG );
	set("exits", ([
		"out"       : "/d/huashan/sheshen",
		"southeast" :__DIR__"hsandao2",
	]));
	set("objects" , ([
		CLASS_D("gaibang") + "/li-futou" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -890);
	set("coor/y", 210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}