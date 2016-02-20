// Room: /d/chengdu/npc/obj/longhucui.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIG"龙湖翠"NOR,({"long hucui", "long", "tea"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一杯散发着清香的龙湖翠。\n");
		set("unit", "杯");
		set("value", 1000);
		set("remaining", 2);
		set("drink_supply", 25);
	}
	
	setup();
}

