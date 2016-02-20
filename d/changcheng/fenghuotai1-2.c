// Room: /d/changcheng/fenghuotai1_2.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "烽火台");
	set("long", WHT @LONG
这里是烽火台的二楼，站在这里你可以看的很远。戍边的将士们就
是长年守卫在这里，防止匈奴的进攻，保卫边疆的安全。从这里向东你
隐隐约约可以看到长城上著名的居庸关。
LONG
NOR );
	set("outdoors", "changcheng");
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
	]));
	set("exits", ([
		"down" :__DIR__"fenghuotai1-1",
	]));
	set("coor/x", -6000);
	set("coor/y", 7000);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}