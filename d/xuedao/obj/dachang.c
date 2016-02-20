// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("鸟羽大氅", ({ "da chang" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "领");
                set("long", "一领用秃鹰长羽织就的大氅. \n");
                set("material", "cloth");
                set("armor_prop/armor", 15);
        }
        setup();
}

