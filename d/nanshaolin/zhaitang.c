// Room: /d/nanshaolin/zhaitang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"斋堂"NOR);
	set("long", @LONG
你面前是一座硕大无比的房屋，这里便是少林全寺寺僧用斋的斋堂。
它由十几间房屋相连而成，可以容纳全寺的僧人一同用斋。堂前的院内
栽着两个垂柳，每棵树下都有一个巨大的铁缸，里面盛满了清水。几个
僧人正往来忙碌着，将院内打扫得十分干净。
LONG );

	set("exits", ([
		"west" : __DIR__"celang-4",
		"east" : __DIR__"fanting1",
		"north" :__DIR__"xjchu",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangshi" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{

	if (  (dir == "west") &&
		(present("mizhi tianou", me) ||
		present("mala doufu", me) ||
		present("furong huagu", me)) &&
		objectp(present("fang shi", environment(me))) )
	switch ( random(2) ) 
	{
		case 0: 
			return notify_fail("方逝和尚把手一伸，说道：食物不得带出斋堂，这是寺中的规定！\n");
			break;
		case 1:
			message_vision("方逝和尚对$N躬身作了个揖道：主持方丈吩咐过，食物不得带出斋堂。", me);
			return notify_fail("\n");
			break;
	}
	
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}
