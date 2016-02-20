//lamei.c
#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name(HIW"腊梅"NOR, ({"la mei", "mei"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枝");
                set("long",HIW
"一枝腊梅，清清冷冷地开着，发散着淡雅的芬芳。严冬时分，
洁白的花儿经受着寒气的侵袭，更显得卓然不群，纯洁娇媚。
春天，毕竟就要到了。\n" NOR);
                set("value", 80);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一枝$n插在鬓间。\n");
                set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");
        }     
        setup();
}
