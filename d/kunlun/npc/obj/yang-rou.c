// Room: /d/kunlun/npc/obj/yang-rou.c
// Last Modified by winder on Jun. 29 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ÑòÈâ", ({"yang rou", "rou"}));
	set_weight(900);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éÓÖ·ÊÓÖÏãµÄÑòÈâ¡£\n");
		set("unit", "¿é");
		set("food_remaining", 3);
		set("food_supply", 40);
	}
}
