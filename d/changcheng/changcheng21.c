// Room: /d/changcheng/changcheng21.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长城");
	set("long", WHT@LONG
由于长期受到风沙的侵蚀，不少城墙已经倒塌。墙角的黄沙中有许
多从城墙上掉下来的青砖。前面不远处就是长城的终点──嘉峪关。由
于这里是西域通往关内的必经之路，所以人也多了起来。只见许多碧眼
金发的商人带着他们的商队匆匆向离去。
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"southwest" : __DIR__"jiayuguan",
		"east"	    : __DIR__"changcheng20",
	]));
	set("no_clean_up", 0);
	set("coor/x", -17000);
	set("coor/y", 9000);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}