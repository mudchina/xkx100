// yaoshi.c
// Last Modified by winder on Sep. 27 2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"红玉钥匙"NOR, ({"hongyu yaoshi", "yaoshi"}));
	set("long", "这是一把看起来很古怪的钥匙。\n");
	set("unit", "把");
	set("weight", 10);
}

