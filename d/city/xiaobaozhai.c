// Room: /city/xiaobaozhai.c

inherit ROOM;

void create()
{
	set("short", "小宝斋");
	set("long", @LONG
抚远大将军挂官出逃后，带了七个老婆，躲在这里偷偷开了这个小
宝斋。卖些当年带回来的金银珠宝，收购一些古董倒卖，着实发了不少
横财。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
//	set("no_clean_up", 0);
	set("objects", ([
		"/quest/weixiaobao" : 1,
	]));
	set("exits", ([
		"east"   : __DIR__"shilijie1",
	]));

	set("coor/x", 0);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}