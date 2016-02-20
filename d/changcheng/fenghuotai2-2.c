// Room: /d/changcheng/fenghuotai2-2.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "烽火台");
	set("long", WHT @LONG
这里是烽火台的二楼，站在这里你可以看的很远。戍边的将士们就
是长年守卫在这里，防止匈奴的进攻，保卫边疆的安全。
LONG
NOR  );
	set("outdoors", "changcheng");
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
	]));
	set("exits", ([
		"down" :__DIR__"fenghuotai2-1",
	]));
	set("coor/x", -10010);
	set("coor/y", 8000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}