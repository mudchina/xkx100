// wg_wuchang4.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "南练武场");
	set("long", @LONG
这是露天练武场，好多人在这里辛苦的练着，你走在场中，没有人
回头看你一眼，都在聚精汇神的练着自己的功夫，地上放着几个练功用
具。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_lang4",
		"west" : __DIR__"wg_wuchang2",
	]));
	set("objects", ([
		__DIR__"npc/wg_daotong" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 21);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
}

