// Room: /d/taishan/yueguan.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "月观峰");
	set("long", @LONG
月观峰是位于南天门西面的山岭，与日观峰东西对峙而名。此处怪
石攒簇，最高的地方一石卓立，名为君子峰。古人言可在此望越国，故
又称越观峰。天晴气朗时，夜晚可观济南府城万家灯火，俗称望府山。
山顶有月观亭；往北走便是泰山的西天门。
LONG );
	set("exits", ([
		"east"    : __DIR__"nantian",
		"northup" : __DIR__"xitian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 350);
	set("coor/y", 770);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}

