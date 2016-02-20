// Room: /d/hengshan/beiyuedian.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "北岳殿");
	set("long", @LONG
北岳殿上负绝壁，下临宫廨，下云级插天，庑门上下，穹碑森立。
殿正中悬风字形匾，上书“贞元之殿”，殿内北岳恒山之神全身塑像，
高可丈余。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"westup"    : __DIR__"huixiantai",
		"eastup"    : __DIR__"yuyang",
		"northup"   : __DIR__"shandao1",
		"southdown" : __DIR__"beiyuemiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 30);
	set("coor/y", 3180);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}

