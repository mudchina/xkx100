// fengjiang.c Óñ·ä½¬
// By Lgg,1998.9

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Óñ·ä½¬", ({"jiang", "feng jiang"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Æ¿ÓÃÓñ·ä³²µ·³ÉµÄ½¬¡£\n");
                set("unit", "Æ¿");
                set("value", 30);
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}
