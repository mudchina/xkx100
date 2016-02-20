// xinjunsan.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
//	add_action("do_eat","eat");
}

void create()
{
	set_name("诸葛行军散", ({"xingjun san"}));

	set("unit", "包");
	set("long", "这是一包预防瘴气的药散，带在身上可以预防瘴气。\n");
	set("value", 0);
//	set("no_drop", "这样东西不能离开你。\n");
	set_weight(200);
	setup();
}
