// Room: /d/baituo/gebi.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "戈壁");
	set("long", @LONG
这里是临近沙漠的戈壁滩，荒无人烟。东边是一望无际的大沙漠，
西北方可以看见一座小镇。
LONG	);
	set("outdoors", "baituo");
        set("no_clean_up", 0);
	set("exits", ([
		"east"      : "/d/xingxiu/shamo4",
		"northwest" : __DIR__"dongjie",
		"north"     : __DIR__"hswz",
	]));
	set("coor/x", -40000);
	set("coor/y", 20000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
