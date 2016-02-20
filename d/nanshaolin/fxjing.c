// Room: /d/nanshaolin/fxjing.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIY"佛心井"NOR);
	set("long", @LONG
这是一口千年古井，井旁是用青石砌成的井台，上面是用生铁铸就
的一个高一尺的井缘。井内深达十几米，黑漆漆的望不到底。井口处有
一个木制的辘轳，用来打水。
LONG );
	set("exits", ([
		"eastup" : __DIR__"ting",
	]));
        set("resource/water",1); 
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1810);
	set("coor/y", -6350);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
