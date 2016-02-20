// difu1.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW "酆都地府" NOR);
	set("long",BLU @LONG
你现在来到一座黑色城楼之前，城楼上刻著三个大字：酆都城。往
南不远处有一座桥，桥上鬼影幢幢，但是却听不到半点声音，再往南就
是鬼门关，可是一旦进了鬼门关，就再也不能出去了；往北走进城楼只
见一片黑漆漆的，只有少许暗红色的火光若隐若现地闪烁著。再往北是
一个大殿。
LONG NOR );
	set("no_fight", 1);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"difu2",
		"south" : __FILE__,
	]));
	set("objects", ([
		__DIR__"npc/niutou": 1,
		__DIR__"npc/mamian": 1,
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;

	if (dir == "south")
	{
		return notify_fail("一个空洞的声音在你耳边响起....\n"+
		"没有回头路了!\n");
	}
	else return 1;
}


