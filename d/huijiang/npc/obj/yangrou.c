// Room: /d/huijiang/npc/obj/yangrou.c
// Last Modified by winder on Sep. 12 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("羊肉", ({ "meat" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块发出强烈膻味的羊肉.\n");
		set("unit", "块");
		set("value", 1000);
		set("eat_msg","$N咬了一口$n，突然见许多苍蝇聚拢到嘴边来。\n");
		set("food_remaining",8);
		set("food_supply", 60);
	}
}
