// meigui.c
#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name(HIY"玫瑰"NOR, ({"meigui", "rose"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", 
"一朵含苞待放的"HIY"玫瑰。\n"NOR);
                set("value", 3500);
                set("flower", 1);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");
        }
        setup();
}
