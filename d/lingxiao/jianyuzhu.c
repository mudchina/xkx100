// Room: /d/lingxiao/jianyuzhu.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "牢房");
	set("long", @LONG
这里漆黑一片，你细细摸索。不久便摸到石门的缝隙，以肩头推去，
石门竟绝不摇晃，不知有多重实。一个脸色苍白的年轻人，垂头丧气地
坐在地上。
LONG );
	set("exits", ([
		"west" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/zhu" : 1,
	])); 
	set("coor/x", -30980);
	set("coor/y", -8900);
	set("coor/z", 130);
	setup(); 
	replace_program(ROOM);
}

