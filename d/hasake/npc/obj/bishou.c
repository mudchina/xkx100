#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("匕首", ({ "bishou", "dao" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄亮晃晃的匕首\n");
                set("value", 500);
                set("material", "steel");                
        }
        init_blade(15);
        setup();
}

