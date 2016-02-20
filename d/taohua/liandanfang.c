// Room: /d/taohua/liandanfang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "炼丹房");
	set("long", @LONG
这是桃花岛主黄药师的秘密练丹房。里面藏着他苦心熬制的丹药和
桃花岛的总图，岛上所有五行生克、阴阳八卦的变化，全记在内。
LONG
	);
	set("exits", ([
	      "out" : __DIR__"jingshe.c",
	]) );
	set("objects", ([
		"/clone/medicine/nostrum/jiuhuawan": 1,
		__DIR__"obj/tupu": 1,
	]));
	set("no_clean_up",0);
	set("coor/x", 9010);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

