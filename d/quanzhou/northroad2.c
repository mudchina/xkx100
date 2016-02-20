// Room: /d/quanzhou/northroad2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "刺桐北路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。西北方连
着一条巷子，可通往城隍庙。
LONG );
	set("outdoors", "quanzhou");
	set("objects", ([
		"/d/city/npc/liumang" : 1,
	]));
	set("exits", ([
		"south"     : __DIR__"northroad1",
		"north"     : __DIR__"northroad3",
		"northwest" : __DIR__"chenghuangxiang",
	]));
	set("coor/x", 1850);
	set("coor/y", -6510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
