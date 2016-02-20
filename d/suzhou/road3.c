// Room: /d/suzhou/road3.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆
匆而过。大道两旁有一些小货摊，似乎是一处集市。向东面望去，就可
以看到苏州城的城墙了。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"road4",
		"east"  : __DIR__"road2",
	]));
	set("coor/x", 800);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
