// Room: /d/yanping/road3.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "石街");
	set("long", @LONG
这是一条青石铺就的长街。延平府依山傍水而建，这条石街便也起
伏跌宕不休。北边是西山，爬上高高的石街，便是州学所在了。东边通
往府衙，西边便是西门。南边紧邻高厚冰冷的青砖城墙。
LONG );
	set("exits", ([
		"west"    : __DIR__"ximen",
		"east"    : __DIR__"road2",
		"northup" : __DIR__"xishan",
	]));
	set("objects", ([
		"/d/village/npc/kid" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1450);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
