// Room: /d/yanziwu/path9.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "青泥小径");
	set("long", @LONG
一条青泥小径蜿蜒延伸向前方。只见小径两侧，花木扶疏，长草幽
深，十分清净。前面看不到亭院，后不见楼阁，唯闻清风扶柳，在低低
吟唱。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"path10",
		"west"   : __DIR__"path8",
	]));
	set("coor/x", 1240);
	set("coor/y", -1250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}