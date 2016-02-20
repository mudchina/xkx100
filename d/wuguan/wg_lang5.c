// wg_lang5.c

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，通向馆主的卧室，这里静悄悄的，没有什么人来，
走廊两边爬满了爬山虎，外面烈日，可是你走在走廊里只觉得一阵
清凉。
LONG);
	set("exits", ([
		"out"   : __DIR__"wg_dating",
		"east"  : __DIR__"wg_woshi",
		"south" : __DIR__"wg_shufang",
	]));
	set("objects", ([
		__DIR__"npc/wg_yahuan" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 31);
	set("coor/y", -40);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

