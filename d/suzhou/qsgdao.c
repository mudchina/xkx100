// Room: /d/suzhou/qsgdao.c
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
		"north"     : __DIR__"qsgdao1",
		"southwest" : __DIR__"tianpingshan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
