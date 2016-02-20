// /d/shenlong/shanlu1 山路
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
脚下踏着细沙，闻到林中飘来的阵阵花香，真觉到了仙境。沿着山
间小路前行，耳边传来阵阵鸟叫，甚是清静，你宛若置身于空明之中。
西面是海滩，北面是通向峰顶的山路，东南有条山溪。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"west"      : __DIR__"haitan",
		"north"     : __DIR__"shanlu2",
		"southeast" : __DIR__"shanxi",
	]));
	set("snaketype", ({"yinhuan", "zsnake"}));
	setup();
}

#include "snakeroom.h";
