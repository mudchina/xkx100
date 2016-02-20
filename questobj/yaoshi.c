// yaoshi.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"红玉钥匙"NOR, ({"hongyu yaoshi", "yaoshi"}));
	set("long", "这是一把看起来很古怪的钥匙。\n");
	set("taskobj", 1);
	set("unit", "把");
	set("value", 100);
	set("weight", 10);
}

