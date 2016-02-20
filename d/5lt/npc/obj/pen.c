// huabi.c

#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("画笔", ({ "huabi", "bi", "dagger" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是传说中马良用过的神笔。\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声从怀中掏出一只$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n揣回怀里。\n");
        }
        init_dagger(50);
        setup();
}

