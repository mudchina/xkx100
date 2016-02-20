// Room: /yangzhou/changchunqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","长春桥");
	set("long",@LONG
长春桥以青石块堆砌，桥身亚于大虹桥，而形制相似，距虹桥约里
许，置短板立柱桥栏。二桥南北相望，为陆行上蜀冈要道。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"west"     : __DIR__"shuiyun",
		"eastup"   : __DIR__"changchunling",
	]));
	set("objects", ([
		"/d/city/npc/popo" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
