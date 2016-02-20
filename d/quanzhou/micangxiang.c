// Room: /d/quanzhou/micangxiang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "米仓巷");
	set("long", @LONG
这是通往粮仓的小路。由于民间匪盗经常抢劫官府粮仓，都督府震
怒之下，特开此路以利府中官兵增援粮仓。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"liangcang",
		"north"     : __DIR__"dudufu",
	]));
	set("coor/x", 1870);
	set("coor/y", -6510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
