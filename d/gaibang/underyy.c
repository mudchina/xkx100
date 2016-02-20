// Room: /d/gaibang/underyy.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "井底密道");
	set("long", @LONG
这是岳阳城内丐帮总舵大院内的古井下的洞里。四周丢满了各种杂
物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG );
	set("exits", ([
		"out"   : "/d/yueyang/gaibangyuan",
		"north" : __DIR__"yyandao2",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/bangzhong" : 1,
	]));
	set("coor/x", -1420);
	set("coor/y", -2250);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
