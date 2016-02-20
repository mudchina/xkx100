// Room: /d/nanshaolin/zhlou5.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "钟楼五层");
	set("long", @LONG
一眼望去，只见蓝天白云，青山列列，令人将尘俗之气，顿为一一
扫。南至前三殿，北到方丈楼，整个南少林寺尽在眼底。北面松树林随
风起伏，林涛阵阵。西面可以看到一大片槐树林。
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou6",
		"down" : __DIR__"zhlou4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}



