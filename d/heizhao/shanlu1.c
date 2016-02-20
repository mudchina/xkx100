// Room: /heizhao/shanlu1.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "密林矮树");
	set("long", @LONG
这里荒无人烟，举步踏到的尽是矮树长草，哪里有路可寻？每
走一步，荆棘都钩刺到小腿，也不觉疼痛，走了一阵，四周林木渐
密，你一步一步走得很慢，只恐一个踏空，跌入山沟陷坑之中。
LONG );
	set("outdoors", "heizhao");
	set("no_clean_up", 0);

	set("exits", ([
		"east" : "/d/henshan/hsroad6",
		"west" : __DIR__"shanlu2",
	]));
	set("coor/x", -3000);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}