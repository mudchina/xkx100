// Room: /d/huanggong/kunningmen.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "坤宁门");
	set("long", @LONG
这是皇宫后廷的后门. 门外是御花园. 门内南连坤宁宫, 由此进入
所谓的三宫六院.
LONG
	);
	set("outdoors", "huanggong");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"kunninggong",
		"north"     : __DIR__"yuhuayuan",
	]));
	set("objects", ([
		__DIR__"npc/ruidong" : 1,
	]));
	set("coor/x", -200);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "south" &&
	objectp(present("rui dong", environment(me))))
		return notify_fail("瑞栋拦住你说：此处禁地，请止步。\n");

	return ::valid_leave(me, dir);
}