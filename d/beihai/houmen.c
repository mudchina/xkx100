// /d/beihai/houmen.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "后门");
	set("long", @LONG
这里是北海花园的后门，门是虚掩着的。门前面站着两个卫士。门
两边长着茂盛的植物。一些苦力背着东西进进出出，甚是忙碌。由门向
北是一条官道。
LONG
	);
	set("exits", ([
		"west"  : __DIR__"jingqing",
		"south" : __DIR__"huafang",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -160);
	set("coor/y", 4100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
