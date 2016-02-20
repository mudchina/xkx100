// Room: /d/gaibang/undercd.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "破床底下");
	set("long", @LONG
这是成都城一个偏僻大院的破床下。四周丢满了各种杂物，还有丐
帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG );
	set("exits", ([
		"out"       : "/d/chengdu/ruin2",
		"northeast" : __DIR__"cdandao2",
	]));
	set("objects",([
//		CLASS_D("gaibang") + "/quan-gq" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -3040);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
