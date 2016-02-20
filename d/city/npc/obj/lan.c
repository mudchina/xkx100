// lan.c 礼篮

inherit ITEM;
#include <ansi.h> 

void create()
{
        set_name(HIY"礼篮" NOR, ({ "li lan", "lan" }));
        set_weight(500);
        set_max_encumbrance(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一只装礼物的竹篮子，细蔑精制而成，手艺可真不错。\n");
                set("value", 1000);
        }
}

int is_container() { return 1; }
