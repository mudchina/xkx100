// Room: /city/huadian.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "维扬花店");
	set("long", @LONG
这里是新近开张的一家鲜花店，店内百花齐放，清香满室。花儿虽
非名种，却也朵朵娇艳欲滴。她们是期待、是问候、是默默的祝福、是
深深的思念……这里的鲜花不知是从一些保密的地方运来？但都是十分
鲜艳而且供货充足。因为是分店，也见不到老板。一个伙计手持花洒，
在花间轻轻走动，精心照料着每朵鲜花。价目表(sign)就挂在墙上。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("item_desc", ([
		"sign" :
"┌────────────"+HIG"购花须知"NOR+"──────────────┐\n"
"│ 一、花店里花儿的价格用(list)查看                           │\n"
"│ 二、买花可直接向伙计购买(buy)：buy <数量> <花草代号>       │\n"
"│ 三、本鲜花店提供送花，送花服务：send <花草代号> to <玩家id>│\n"
"│ 四、请用(help flower)来查询花朵含义和资料。                │\n"
"└──────────────────────────────┘\n"
	]));
	set("objects", ([
		__DIR__"npc/huoji3" : 1,
	]));
	set("exits", ([
		"east"      : __DIR__"shaoyaopu",
		"northwest" : __DIR__"caohecexiang",
	]));
	set("coor/x", -40);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
