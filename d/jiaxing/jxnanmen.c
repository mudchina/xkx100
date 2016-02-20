// Room: /d/jiaxing/jxnanmen.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "嘉兴南门");
	set("long", @LONG
这里是嘉兴的南门。周围长着茂密的竹林。东面是座庙宇。向南可
入福建。向东南就是号称天堂的杭州城了。
LONG );
	set("exits", ([
		"north"    : __DIR__"jiaxing",
		"east"     : __DIR__"tieqiang",
		"south"    : __DIR__"jnroad4",
		"southeast": "/d/hangzhou/road1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiaxing");
	set("coor/x", 1500);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}