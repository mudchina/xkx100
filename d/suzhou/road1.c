// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "麻石大道");
	set("long", @LONG
你走在一条麻石大道上，人来人往非常繁忙，不时地有人骑着马匆
匆而过。大道两旁有一些小货摊，似乎是一处集市。往南面就是号称天
堂的苏州城了。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"beimen",
		"southwest" : __DIR__"huqiu",
		"northeast" : __DIR__"sanglin",
		"northwest" : "/d/wuxi/road4",
	]));
	set("coor/x", 850);
	set("coor/y", -900);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
