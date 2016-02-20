#include <armor.h>

inherit WAIST;

void create()
{
        set_name("荷包", ({ "he bao", "hebao", "bao"}) );
        set_weight(500);
        set_max_encumbrance(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只小小的荷包，里面可以装一些小东西。\n");
                set("material", "silk");
                set("no_get",1);
                set("armor_prop/parry", 1);
                set("value", 1000);
        }
        setup();
}

