// Room: /d/chengdu/npc/obj/piang.c ·òÆÞ·ÎÆ¬
// Last Modifyed by Winder on Jan. 4 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("·òÆÞ·ÎÆ¬", ({"piang"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»µú·òÆÞ·ÎÆ¬¡£\n");
		set("unit", "µú");
		set("value", 200);
		set("food_remaining", 6);
		set("food_supply", 120);
	}
}
