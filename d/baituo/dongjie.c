// Room: /d/baituo/dongjie.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "东街");
	set("long", @LONG
这里是小镇的东街。南边有个打铁铺，里面传来丁丁当当的声音。
东南方是荒凉的戈壁，东北方有条小路可上山。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"west"      : __DIR__"xijie",
		"south"     : __DIR__"datiepu",
		"southeast" : __DIR__"gebi",
		"northeast" : __DIR__"xiaolu1",
	]));
	set("objects",([
		__DIR__"npc/playboy" : 1,
	]));
	set("coor/x", -49980);
	set("coor/y", 19980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
