// mapo-doufu.c ÂéÆÅ¶¹¸¯
// Last Modified by Sir on May. 22 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ÂéÆÅ¶¹¸¯", ({"mapo doufu", "doufu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅèÑÕÉ«ºìÁÁ£¬Ï¸ÖĞ´øÄÛ£¬ÏãÀ±¿É¿ÚµÄÂéÆÅ¶¹¸¯¡£\n");
		set("unit", "Åè");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
