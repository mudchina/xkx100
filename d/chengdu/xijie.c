// Room: /d/chengdu/xijie.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这条街满街的招牌幌子，随风飘扬，两边是鳞立栉比的店铺，还有
一些小摊小贩在路边做生意，偶尔有官兵列队经过。北边一条小巷，进
进出出都是些衣冠楚楚的读书人，南边有个当铺。再向西则是出城的路。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"xijie1",
		"west"  : __DIR__"westgate",
		"north" : __DIR__"xiaoxiang",
		"south" : __DIR__"dangpu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

