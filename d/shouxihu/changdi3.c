// Room: /yangzhou/changdi3.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "柳岸长堤");
	set("long", @LONG
长堤遍植杨柳，间以桃花。堤侧是盈盈西湖水，草长莺飞时节，红
男绿女，相约其间，长堤柳丝拂水，风情万种。北去是平山坞，南边是
望春楼。
LONG );
	set("outdoors", "shouxihu");
	set("objects", ([
		"/d/village/npc/girl" : 2,
	]));
	set("exits", ([
		"north" : __DIR__"pingshanwu",
		"south" : __DIR__"wangchunlou",
	]));
	set("coor/x", -30);
	set("coor/y", 110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}