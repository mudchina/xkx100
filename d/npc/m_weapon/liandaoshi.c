// ROOM liandaoshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "炼刀场");
	set("long", @LONG
这里是玄兵古洞的炼刀场。四处充满了金属的气味，炙热的气浪冲
的人不由打了个趔趄。一个皮肤黝黑的小伙正坐在一块石头上休息，手
中一个巨大的锤头正不停的来回摆动着。看来这小伙快要睡着了。
LONG );
	set("exits", ([
		"south" : "/d/xingxiu/tianroad5",
	]));
	set("objects", ([
		__DIR__"npc/shidao" :1,
	]));
	set("coor/x", -52010);
	set("coor/y", 20150);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
