// qhcwan.c  青花瓷碗

 inherit ITEM;
inherit F_LIQUID;
// inherit COMBINED_ITEM;

void create()
{
        set_name("缺口的青花瓷碗", ({"qinghua ciwan", "wan", "ciwan"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个缺了口的粗瓷碗。\n");
                set("unit", "个");
                set("value", 100);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "清水",
                "remaining": 15,
                "drunk_apply": 3,
//              "slumber_effect": 100,
        ]));
}
