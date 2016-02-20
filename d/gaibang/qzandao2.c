// Room: /d/gaibang/qzandao2.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是丐帮极其秘密的地下通道，乃用丐帮几辈人之心血掘成。 
LONG );
	set("exits", ([
		"southeast" : __DIR__"underqz",
		"northwest" : __DIR__"qzandao1",
	]));
	set("objects",([
		FOOD_DIR+"jitui" : 3,
		LIQUID_DIR+"jiudai" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 1000);
	set("coor/y", -500);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
