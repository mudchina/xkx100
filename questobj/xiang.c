// xiang.c
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(HIC"龙涎香"NOR, ({"longxian xiang","xiang" }));
	set("unit","块");
	set("taskobj", 1);
	set("long","这是一块黑红色的东西，散发出奇异香气,据说可以吸引毒虫。\n");
	set("value", 0);
	set_weight(50);
	setup();
}

