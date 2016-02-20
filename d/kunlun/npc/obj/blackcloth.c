// Room: /d/kunlun/npc/obj/black.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(BLK"ºÚõõôÃ"NOR, ({ "heidiao cloth","cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 5000);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}

