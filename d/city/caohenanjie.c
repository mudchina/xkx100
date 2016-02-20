// Room: /yangzhou/caohenanjie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","草河南街");
	set("long",@LONG
这里街道比草河东岸的长街窄的多，也干净平整的多，行人稀少，
河岸边上的杨柳、碧桃倒影河中，摇曳多姿，整条街显的极为幽静。街
边少有店铺酒楼，大多门户紧闭，两边伺立着一对石狮，看来这一带住
的大多是官宦缙绅人家。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"menting",
		"east"      : __DIR__"taipingqiao",
		"south"     : __DIR__"heyuan",
		"north"     : __DIR__"caohexiaojie",
		"northwest" : __DIR__"chanzhimenqian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}