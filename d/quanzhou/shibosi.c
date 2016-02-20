// Room: /d/quanzhou/shibosi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "市舶司");
	set("long", @LONG
这是负责接待海外使节及筹备出海西洋必要手续的地方。门口左右
两边各有一个青石狮子，形态矫健，仰天高吼。西北边通往顺济桥，西
南边通往港口路，北边的街道尽头则是涂门集。
LONG );
	set("exits", ([
		"north"     : __DIR__"road2",
		"southwest" : __DIR__"portroad3",
		"northwest" : __DIR__"shunjiqiao",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1860);
	set("coor/y", -6610);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
