// fengmi.c Óñ·äÃÛ
// By Lgg,1998.9

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("Óñ·äÃÛ", ({"mi", "fengmi", "feng mi"}));
        set_weight(750);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¹ŞÓñ·äÄğ³ÉµÄÃÛ¡£\n");
                set("unit", "¹Ş");
                set("value", 20);
                set("max_liquid", 12);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "fengmi",
                "name": "·äÃÛ",
                "remaining": 12,
                "drunk_supply": 9,
        ]));
}

