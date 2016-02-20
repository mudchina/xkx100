// Room: /d/gaibang/yyandao2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是丐帮极其秘密的地下通道，乃用丐帮几辈人之心血掘成。 
LONG );
	set("exits", ([
		"south" : __DIR__"underyy",
		"north" : __DIR__"yyandao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1000);
	set("coor/y", -1000);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
