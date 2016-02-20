// cloth.c

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("鹑衣", ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "丐帮弟子行走江湖的时候，一般都是穿这样的衣服。");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

