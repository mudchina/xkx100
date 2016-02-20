// Room: /d/huangshan/shisun.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "石笋杠");
	set("long", @LONG
这里石柱林立，形同竹笋，千姿百态。每当黎明破晓，旭日东升，
朝霞遍染群峰，烟云迷漫深壑，这种神奇瑰丽的画面使得慕名而来的人
心悦诚服。
LONG
	);
	set("exits", ([ 
		"southwest" : __DIR__"sanhua",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
