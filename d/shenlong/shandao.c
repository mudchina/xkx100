// 山道 /d/shenlong/shandao
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
转过两个山坡，你已行走在一个山道之中，山道的北面是峰顶，向
下是山坡。抬头遥见峰顶建着几座大竹屋，耳边隐隐约约传来「锵锵」
的刀剑撞击声和有人高声喧哗的声音，看来离山顶不远了。山道狭窄，
只能容一人通过。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"northup"   : __DIR__"fengding",
		"southdown" : __DIR__"shanpo2",
	]));
	set("objects", ([
		__DIR__"npc/old" : 1,
	]));
	set("snaketype", ({"snake", "fushe"}));
	setup();
}

#include "snakeroom.h";
