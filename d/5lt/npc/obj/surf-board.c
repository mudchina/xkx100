// surf-board.c

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("冲浪板", ({"surf board", "board"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声从怀中掏出一只$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n揣回怀里。\n");
        }
        init_dagger(50);
        setup();
}

