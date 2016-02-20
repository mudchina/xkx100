#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("锄头", ({ "chu tou", "chu" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是乡下农民种地用的锄头。\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N将$n从肩上放了下来，握在手中。\n");
                set("unwield_msg", "$N将$n扛在肩上。\n");
        }

        init_hammer(25);
        setup();
}

