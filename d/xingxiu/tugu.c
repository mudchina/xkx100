// Room: /d/xingxiu/tugu.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;

void create()
{
	set("short", "吐谷浑伏俟城");
	set("long", @LONG
这里是吐谷浑都城。吐谷浑原为鲜卑的一支，游牧于北方。后来首
领吐谷浑率所部西迁于此。以吐谷浑为国名。其可汗现正居于伏俟城内。
城内混居了周围的多个民族，走在大街上看到和听到的无不透着新奇。
LONG);
	set("outdoors", "xiyu");
	set("exits", ([
		"east"      : __DIR__"shazhou",
		"northwest" : __DIR__"silk5",
		"south"     : __DIR__"nanjiang",
	]));

	set("objects", ([
		__DIR__"npc/trader" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -23500);
	set("coor/y", 900);
	set("coor/z", 0);

	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

