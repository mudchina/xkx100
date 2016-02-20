// Room: /d/suzhou/qsgdao1.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long",@long
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆
匆而过。大道两旁有一些小货摊，似乎是一处集市。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"south" : __DIR__"qsgdao",
		"north" : __DIR__"qsgdao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
