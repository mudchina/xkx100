// Room: /d/yueyang/guangchang.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
这是一个不大不小的青石广场。广场周围是一些低矮的民房，南端
有一个戏台，戏台的雨篷被风雨吹得有些破败，台上堆了不少杂物。广
场上搭了不少小窝棚，看来有些凌乱。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"xijie",
	]));
	set("objects", ([
		__DIR__"npc/liumang" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("coor/x", -1420);
	set("coor/y", -2280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
