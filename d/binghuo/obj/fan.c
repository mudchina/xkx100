// fan.c
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name("帆布", ({"fan bu", "fan" }));
	set("unit", "块");
	set("long", "这是一块黑黝黝的帆布，看不出有什么用。\n");
	set("value", 0);
	set("no_drop", "这样东西不能离开你。\n");
	set_weight(500);

        setup();
}

