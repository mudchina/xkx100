// Room: /d/lingxiao/houyuan1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","后园");
	set("long",@LONG 
这里是凌霄派的后园。小桥流水，菏塘低阁。层台耸翠，上出重霄。
飞阁流丹，下临无地。在这万里雪山之上，象这种温暖如春的地方，实
不多见，也难怪当年凌霄祖师要建派于此了。菏塘中的一方假山上，一
缕清泉汩汩流出，雾气蔼蔼，如梦如幻。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"houyuan2",  
		"south"  : __DIR__"zhongting", 
	]));
	set("objects",([ /* sizeof() == 1 */
		CLASS_D("lingxiao")+"/first" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8860);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

