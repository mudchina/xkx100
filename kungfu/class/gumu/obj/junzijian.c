// junzijian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIC "君子剑" NOR, ({ "junzi jian", "jian", "sword" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一口遍体通黑的剑，剑身上用金丝锩着几个字：\n"
                            "谦谦君子，温润如玉\n");
                set("value", 12000);
                set("material", "steel");
                set("weapon_prop/personality", 24);
                set("wield_msg", "$N低叹一声，将$n缓缓抽出剑鞘。\n");
                set("unwield_msg", "$N手一晃，$n已然回鞘。\n");
        }
        init_sword(35);
        setup();
}
