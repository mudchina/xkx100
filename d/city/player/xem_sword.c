// xem_sword.c
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIR"回风剑"NOR, ({ "huifeng", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N掐诀念咒, 一口$n破空而至, 落入$N的手中。\n");
                set("unwield_msg", "$n从$N手中一跃而起, 啸声中破空而去。\n");
        }
        init_sword(30);
        setup();
}

