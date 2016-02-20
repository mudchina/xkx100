// Room: /d/chengdu/npc/obj/qingcai.c 青菜
// Last Modifyed by Winder on Jan. 4 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("青菜", ({"Qingcai", "cai"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一棵绿油油的青菜。\n");
		set("unit", "棵");
		set("value", 30);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
