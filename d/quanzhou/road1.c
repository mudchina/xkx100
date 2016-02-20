// Room: /d/quanzhou/road1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
这是泉州南面东西向的一条干道，规模不大。南去可达海外交通使
节府，东面是一所绸缎庄。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"east"   : __DIR__"chouduan",
		"south"  : __DIR__"road2",
		"north"  : __DIR__"tumenji",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6590);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
