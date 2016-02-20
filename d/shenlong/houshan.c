// /d/shenlong/houshan 后山
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
这里是后山，人迹罕至，杂草丛生，前面的路越来越小，路上还有
什么动物爬过的痕迹，你越走越害怕，不时回头。突然，你看见草堆中
似乎有一个洞，但是又看不太清楚。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"southdown" : __DIR__"kongdi",
		"northdown" : __DIR__"luanshi",
	]));
	set("snaketype", ({"mangshe"}));
	setup();
}

#include "snakeroom.h";
