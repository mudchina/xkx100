#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIG"天麻"HIW"银耳"HIY"汤"NOR, ({"tianma soup"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                           set("long", "这是“四季美饭庄”的一道名菜，香喷喷地冒着热气。\n");
                set("unit", "碗");
                set("value", 800);
                set("max_liquid", 30);
             }
                set("liquid", ([
                    "name" : HIG"天麻"HIW"银耳"HIY"汤"NOR,
                    "remaining" : 8,
                    "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

