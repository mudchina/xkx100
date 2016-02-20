// Room: /5lt/zoulang3.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是走廊。
LONG);
	set("exits", ([
		"north"  : __DIR__"bobingwu",
		"west"   : __DIR__"zoulang1",
	]));
        set("no_fight","1");
	set("no_clean_up", 0);
	set("coor/x", -135);
	set("coor/y", 5);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}