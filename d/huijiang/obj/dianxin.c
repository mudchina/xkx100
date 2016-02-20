// Room: /d/huijiang/obj/dianxin.c
// Last Modified by winder on Sep. 12 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("点心", ({"dian xin", "dianxin"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟香喷喷的点心，还冒着热气.\n");
		set("unit", "碟");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
