// /d/shenlong/shanlu2 山路2
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
脚下的细沙渐渐变成了山上的碎石，山路幽静，你闻到林中飘来的
阵阵花香，真觉到了仙境。沿着山间小路前行，耳边传来阵阵鸟叫，甚
是清静，你宛若置身于空明之中。北面是山坡，南面是蜿蜒的山路。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"south"     : __DIR__"shanlu1",
		"northup"   : __DIR__"shanpo1",
		"northeast" : __DIR__"shanqiu",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/zhang" : 1,
	]));
	set("snaketype", ({"snake", "zsnake"}));
	setup();
}

#include "snakeroom.h";

