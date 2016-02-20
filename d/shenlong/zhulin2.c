// /d/shenlong/zhulin2 竹林2
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
这儿是一片密实的竹林，光线暗淡，你一不小心就会被脚下的枝条
绊个跟头。附近似乎有轻微的沙沙声，好象是海风吹过又好象是虫子爬
过，你觉得有点不对劲，但又说不出是什么。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"south" : __DIR__"zhulin1",
		"north" : __DIR__"liangongfang",
	]));
	set("snaketype", ({"zsnake"}));

	setup();
}

#include "snakeroom.h";
