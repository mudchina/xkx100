// arrow.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIC"凤尾箭"NOR, ({ "fengwei jian", "arrow" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "束");
                set("value", 0);
                set("base_unit", "支");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "iron");
                set("long", "凤尾箭连珠箭发，势道凶猛。\n");
                set("wield_msg", HIC"$N迅速地从箭袋中抽出一束凤尾箭，拉弦在手，就待发出！\n"NOR);
                set("unwield_msg",HIC"$N将手里剩下的凤尾箭放回箭袋中。\n"NOR);
        }
        set_amount(20);
        init_throwing(25);
        setup();
}
