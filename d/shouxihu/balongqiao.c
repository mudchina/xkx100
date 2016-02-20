// Room: /yangzhou/balongqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","八龙桥");
	set("long",@LONG
吹台和小金山之间是一段柳岸长堤，长堤中段架有两侧雕塑八龙头
花岗岩桥，这就是八龙桥。
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"north"   : __DIR__"chuitai",
		"southup" : __DIR__"changchunling",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}