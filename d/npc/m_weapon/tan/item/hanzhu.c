//yuzhu.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG"寒丝羽竹"NOR, ({ "han zhu","zhu"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long","这是一根寒丝羽竹，通体晶莹微微泛着绿光晶莹剔透竟似用水晶\n雕成的，拿在手中轻若无物，似乎是制造兵器的绝好材料。\n");
                set("value", 0);
                set("material", "bamboo");
              }
}
void owner_is_killed()
{
        destruct(this_object());
}
