// haibaorou.c º£±ªÈâ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("º£±ªÈâ", ({"haibao rou", "rou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éÏÊÑªÁÜÀì·ÊÄÛµÄº£±ªÈâ¡£\n");
		set("unit", "¿é");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 100);
	}
}
