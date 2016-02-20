// mifang.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(HIY"米饭"NOR, ({ "mifang" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个碗香喷喷米饭。\n");
                set("unit", "碗");
                set("value", 0);
                set("food_remaining", 4);
                set("food_supply", 60);
        }
}
