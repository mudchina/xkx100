// Room: /d/baituo/zhuyuan.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","竹园");
	set("long", @LONG
这里是一个幽静的竹园，高高低低的翠竹把这里装点得别有情致。
西北方是后院，东北方有个兔苑。南边是花园。
LONG	);
	set("exits",([
		"northeast" : __DIR__"tuyuan",
		"northwest" : __DIR__"houyuan",
		"south"     : __DIR__"huayuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "baituo");
	set("coor/x", -50010);
	set("coor/y", 20070);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
