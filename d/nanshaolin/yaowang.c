// Room: /d/nanshaolin/yaowang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"药王院"NOR);
	set("long", @LONG
一进药王院，扑鼻而来的是浓郁的药香。房间内排满了装满各类药
材的大药柜，每个药柜都有上百个装药的抽屉贴满了各类药名。西边是
一个巨大红杉木柜，柜上贴着方丈印的封条。一位中年僧人正来回忙碌
着指点众执役僧称量药品，熬药煎汤。
LONG );
	set("exits", ([
		"west" : __DIR__ "songshu1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangji" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

