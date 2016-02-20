// blackcloth.c 黑袍
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("黑袍", ({ "hei pao","pao","blackcloth" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "steel");
		        set("long","这是一件杀手最喜欢穿的黑色长袍");
				set("value", 0);
                set("armor_prop/armor", 50);
        }
        setup();
}

