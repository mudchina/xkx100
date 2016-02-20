// /d/yixing/clhuayuan.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这个花园是典型的江南风格，精巧细致。园中花卉虽没有什么名贵
品种，也是争奇斗妍。正中一条石子铺就的小路，上面遍布青苔，甚是
湿滑。向东是一条甬道。
LONG );

	set("exits", ([
		"west"  : __DIR__"clzoulang2",
		"east"  : __DIR__"clyongdao",
		"south" : __DIR__"clbajiaoting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yixing");
	setup();
	replace_program(ROOM);
}

