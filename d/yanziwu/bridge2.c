// Room: /d/yanziwu/bridge2.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "泻玉桥");
	set("long", @LONG
莲韵塘水从蔓陀峰中流而下，从泻玉桥下流入太湖中。水流过此桥
下，流速甚快，溅起无数水花，如飞琼落玉一般，伴随着古琴流音般的
水响。站在桥上，看着桥心“泻玉”二字，仿佛桥下流走的不是清水，
而是你无悔的年华。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"path11",
		"west"  : __DIR__"path16",
	]));
	set("coor/x", 1230);
	set("coor/y", -1220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}