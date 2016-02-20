// Room: /d/gumu/obj/goldkey.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"金钥匙"NOR, ({"jin yaoshi","gold key", "key"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","把");
		set("long","这是一把黄金钥匙，金光闪闪的，似乎和古墓的某些秘密有关。\n");
		set("value", 1000);
		setup();
	}
}

