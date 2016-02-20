// culiu-baicai.c ´×Áï°×²Ë
// Last Modified by Sir on May. 22 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("´×Áï°×²Ë", ({"culiu baicai", "baicai"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»Åèºì°×Ïà¼ä£¬´àÄÛË¬¿Ú£¬ÇåÏãÓÕÈËµÄ´×Áï°×²Ë¡£\n");
		set("unit", "Åè");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
