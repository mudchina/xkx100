// Room: /d/gaibang/underfz.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "大榕树下");
	set("long", @LONG
这是福州大榕树下的小洞。里面破破烂烂的，丢满了各种杂物，还
有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG );
	set("exits", ([
		"out"       : "/d/fuzhou/nanmendou",
		"northwest" : __DIR__"fzandao2",
	]));
	set("objects",([
//		CLASS_D("gaibang") + "/li-sh" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6320);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}