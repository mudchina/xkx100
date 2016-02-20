#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"¾Å»Æ±ı"NOR, ({"jiuhuang bing","bing"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "¾£ÖİÃûµã£¬ËÖËÉÏãÌğ¡£\n");
                set("unit", "¿é");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 50);
        }
}

