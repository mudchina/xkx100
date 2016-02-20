// Room: /heizhao/xixiang.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "西厢房");
	set("long", @LONG
这里是一灯大师的弟子们平常打坐练功的地方。地上铺着一些
蒲团，墙边靠着一些兵器，地上的青砖都已经陷出足印了，青砖被
蹭得十分光滑。
LONG );
	set("objects", ([
		"/d/shaolin/npc/mu-ren": 6,
	]));
	set("exits", ([
		"east"       : __DIR__"chanyuan",
	]));
	set("coor/x", -5030);
	set("coor/y", -1200);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}