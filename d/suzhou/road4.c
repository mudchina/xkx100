// Room: /d/suzhou/road4.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆
匆而过。大道两旁有一些小货摊，似乎是一处集市。东面就是苏州城了。
西北方通向寒山寺。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"hanshansi",
		"south"     : __DIR__"tulu1",
		"east"      : __DIR__"road3",
	]));
	set("coor/x", 790);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
