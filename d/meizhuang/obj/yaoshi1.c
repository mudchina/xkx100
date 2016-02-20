// yaoshi.c
// Last Modified by winder on Sep. 27 2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"钢芯钥匙"NOR, ({"gang yaoshi", "yaoshi"}));
	set("long", "这是一把钢芯钥匙，看起来非常坚固。\n");
	set("unit", "把");
	set("weight", 10);
}

