// Room: /d/changcheng/beisilou.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "北四楼");
	set("long", WHT@LONG
登上北四楼极目远眺，但见长城从西南面的山脊曲折蜿蜒而来，莽
莽苍苍，横亘天外，在这里突然折向南面，不久再度逶迤东去，恰似一
条巨大的游龙，不知其所来，也不知其所去。
LONG
NOR  );
	set("outdoors", "changcheng");
	set("exits", ([
		"southwest" :__DIR__"badaling",
		"southup"   :__DIR__"nansilou",
	]));
	set("no_clean_up", 0);
	set("coor/x", 2000);
	set("coor/y", 6000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}