// Room: /yangzhou/chunboqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","春波桥");
	set("long",@LONG
小红桥是一座木制拱桥，此桥西接桃花坞，东连四桥烟雨楼前南端
小岛，与四桥烟雨楼相通。
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"west" : __DIR__"taohuawu",
		"east" : __DIR__"siqiaoyanyu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}