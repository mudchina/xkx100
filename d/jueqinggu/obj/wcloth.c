// Room: /d/jueqinggu/obj/wcloth.c
// Last Modified by winder on Feb. 17 2001

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(WHT"°×É´ÄÞÉÑ"NOR, ({ "white cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 70);
        }
        setup();
}

