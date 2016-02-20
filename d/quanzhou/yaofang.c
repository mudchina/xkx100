// Room: /d/quanzhou/yaofang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "药房");
	set("long", @LONG
这里是济世堂配药炼药的地方，屋子正中放了一只炼药用的药臼，
一个小厮正不停的加药、鼓火、添水，炉中不停的冒出腾腾水雾，并散
发着浓浓的药气。
LONG );
	set("exits", ([
		"west" : __DIR__"jishitang",
	]));
	set("objects", ([
		"/clone/misc/yaojiu" : 1,
		__DIR__"npc/xiaosi" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
