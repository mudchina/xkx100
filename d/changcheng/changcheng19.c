// Room: /d/changcheng/changcheng19.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长城");
	set("long", WHT @LONG
你唱着，唱着，忽然迎面刮来一阵大风，吹的你满头，满脸，满嘴
的沙子。你的急忙闭上了嘴，兴致一下全没了。你看了一下周围，只见
四周已经很少看到植物，到处是黄沙，使人感到一片荒凉。
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"southwest" :__DIR__"changcheng20",
		"northeast" :__DIR__"changcheng18",
	]));
	set("no_clean_up", 0);
	set("coor/x", -15000);
	set("coor/y", 10000);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}