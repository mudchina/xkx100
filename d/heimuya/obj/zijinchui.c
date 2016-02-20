// bishuijian.c
// for 岳灵珊

#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("紫金锤", ({ "zijin chui", "chui", "hammer" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", "这是一枚由海底金母铸造而成的大锤，看上去紫\n"
			    "光盈盈, 显得极是沉重。\n");
                set("value", 10000);
                set("material", "steel");
                set("wield_msg", "$N振臂一挥, 抡出一枚沉重的$n。\n");
                set("unwield_msg", "$N将手中的$n慢慢收回。\n");
        }
        init_hammer(40);
        setup();
}

