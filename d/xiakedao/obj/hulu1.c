//hulu1.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("葫芦", ({"rhulu", "hu"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个红色的葫芦。\n");
                set("unit", "个");
                set("value", 100);
                set("max_liquid", 3);
        }
        // because a container can contain different liquid
        // we set it to contain water at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "药酒",
                "remaining": 3,
                "drunk_supply": 10,
        ]));
}

