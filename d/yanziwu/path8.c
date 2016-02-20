// Room: /d/yanziwu/path8.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "青泥小径");
	set("long", @LONG
云锦楼后，是一条青泥小径，小径两侧，林木幽深，十分清净。小
径在曲折中蜿蜒延伸，前面看不到亭院，后不见楼阁，唯闻清风扶柳，
低低吟唱。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"yunjin1",
		"east"   : __DIR__"path9",
	]));
	set("coor/x", 1230);
	set("coor/y", -1250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}