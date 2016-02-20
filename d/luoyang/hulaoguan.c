// Room: /d/luoyang/hulaoguan.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "虎牢关");
	set("long",  @LONG
虎牢关又称汜水关、成皋关，因西周穆王在此牢虎而得名。历朝历
代，无不在此设防。虎牢南连嵩岳，北濒黄河，山岭交错，自成天险。
大有一夫当关，万夫莫开之势，为历代兵家必争之地，尤以三英战吕布
更使其名声大震。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"road2",
		"east" : __DIR__"road0",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -180);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

