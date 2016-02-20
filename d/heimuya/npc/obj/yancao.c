
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "ÉÏµÈÑÌ²Ý", ({ "shangdeng yancao", "yancao" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°ü");
                set("value", 1000);
                set("material", "leather");           
        }
        setup();
}

