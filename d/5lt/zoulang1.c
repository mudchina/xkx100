// Room: /5lt/zoulang1.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是走廊。
LONG);
	set("exits", ([
		"north"  : __DIR__"paijuroom",
		"south"  : __DIR__"eroad1",
		"east"   : __DIR__"zoulang3",
		"west"   : __DIR__"zoulang2",
	]));
        set("no_fight","1");
	set("no_clean_up", 0);
	set("coor/x", -140);
	set("coor/y", 5);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}