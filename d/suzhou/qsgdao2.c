// Room: /d/suzhou/qsgdao2.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long",@long
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆
匆而过。大道两旁有一些小货摊，似乎是一处集市。北边通向苏州城。
long);
	set("outdoors", "suzhou");                        
	set("objects",([
		__DIR__"npc/yetu" : 2,
	]));
	set("exits",([
		"north" : __DIR__"nanmen",
		"south" : __DIR__"qsgdao1",
	]));
	set("coor/x", 850);
	set("coor/y", -1060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
