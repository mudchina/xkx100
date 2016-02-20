// Room: /d/huangshan/songgu.c
// Last Modified by winder on Sep. 27 2001
inherit ROOM;
void create()
{
	set("short", "松谷庵");
	set("long", @LONG
长长的石阶，沿途尽是茂林修竹，树枝上挂着云雾草，越发增加了
清凉幽静的感觉，和前面的险峻截然不同。走完石阶便是松谷庵，这是
一座明代的道观，庵前翠竹如海，诸潭环布，景色清幽至极。后面便是
五龙潭和翡翠池。
LONG
	);
	set("exits", ([ 
		"north"  : __DIR__"feicui",
		"south"  : __DIR__"diezhang",
		"eastup" : __DIR__"caishi",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
