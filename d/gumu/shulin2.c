// shulin2.c 树林
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
你走在一条林间的小道上，四周都是树。远处似乎有一角建筑的飞
檐从树丛中露了出来，也许附近的山上有一座道观之类。这些树你大都
叫不出名字来，树龄都已经很长了。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"southwest" : __DIR__"shulin3",
		"northeast" : __DIR__"shulin1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3210);
	set("coor/y", 60);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
