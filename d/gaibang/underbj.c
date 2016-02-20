// Room: /d/gaibang/underbj.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "街边狗洞");
	set("long", @LONG
这是北京城一条偏僻街边的狗洞里。四周丢满了各种杂物，
还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG );
	set("exits", ([
		"out"   : "/d/beijing/aobai1",
		"south" : __DIR__"bjandao2",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/quan-gq" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4050);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
