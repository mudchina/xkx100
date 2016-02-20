//Edited by fandog, 02/15/2000
#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name(HIY"金波旬花"NOR, ({"jinbo xunhua", "hua"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", 
"这金色的花朵，便是奇毒无比的金波旬花。“波旬”两字是
梵语，是“恶魔”的意思。这毒花是从天竺传来的，原来天
竺人叫它为“恶魔花”，\n");
                set("value", 90);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");
        }
        setup();
}

