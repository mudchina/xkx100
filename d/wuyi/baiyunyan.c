// Room: /d/wuyi/baiyunyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "白云岩");
	set("long", @LONG
白云岩位于九曲尽头。山上白云寺，距今已经一千五百年了。全寺
分为四层依岩而建，红墙雕栏，气势宏伟。登上白云岩顶，只见古木参
天，翠竹竟秀。俯看山下，九曲清溪，竹筏悠悠，真有仙凡感觉。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast"  : __DIR__"path9",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1350);
	set("coor/y", -4960);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

