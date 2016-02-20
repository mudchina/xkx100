// Room: /d/nanyang/npc/obj/xianbing.c
// Last Modified by winder on Nov. 20 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ÏÚ±ý", ({"xian bing", "bing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿é¼åµÃ½¹»Æ½¹»ÆµÄÏÚ±ý¡£\n");
		set("unit", "¿é");
		set("value", 50);
		set("food_remaining", 2);
		set("food_supply", 40);
	}
}

