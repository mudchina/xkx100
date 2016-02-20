//zhaohong.c
//
// This is the basic equip for yang.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Ôæºì¶ÐÃæÆ¤ÅÛ", ({ "pi pao","pao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("value",3000);
                set("armor_prop/armor", 6);
        }
        setup();
}

