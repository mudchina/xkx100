// paigu.c ¿¾Ñ¼

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ÎŞÎı½´ÅÅ¹Ç", ({"jiang paigu", "paigu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éÅçÏãµÄÎŞÎı½´ÅÅ¹Ç¡£\n");
		set("unit", "¿é");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
