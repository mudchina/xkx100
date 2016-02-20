// Room: /d/changcheng/changcheng20.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长城");
	set("long", WHT @LONG
由于长期受到风沙的侵蚀，不少城墙已经倒塌。墙角的黄沙中有许
多从城墙上掉下来的青砖。抬眼望去，只见城墙外是一望无边的黄沙，
周围安静极了，向一片死亡的世界，偶尔天上飞过一只苍鹰。远远的可
以看见西边有一座关卡。
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"west"      :__DIR__"changcheng21",
		"northeast" :__DIR__"changcheng19",
	]));
	set("no_clean_up", 0);
	set("coor/x", -16000);
	set("coor/y", 9000);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}