// Room: /d/lingxiao/weideju.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","威德居");
	set("long",@LONG
这是白自在的寝室，家具屋饰，极尽豪华，谓金碧辉煌，桂殿兰宫。
但现在白自在已不知去向，只剩他的一个妾室，还在这里抽抽噎噎地哭。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"book",   
	]));
	set("objects", ([  
		__DIR__"npc/yaoniang" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

