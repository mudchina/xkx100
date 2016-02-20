// paomo.c 
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"ÑòÈâÅİâÉ"NOR, ({"yangrou paomo", "paomo"}));
	set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","Ò»ÍëÈÈºõºõÏãÅçÅçµÄÑòÈâÌÀ£¬ÅİÉÏÄíµÃËéËéµÄâÉ£¬Õæ½â·¦£¡\n");
		set("unit", "Íë");
 		set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 100);
	}
}
