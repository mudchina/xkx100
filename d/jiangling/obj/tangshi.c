//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"唐诗选辑"NOR, ({"tangshi book","book","tangshi"}));
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一本纸页发黄的古书，里面还夹着几张做鞋和绣花的纸样。\n");
                set("unit", "本");
                set("material", "paper");
        }
        setup();
}

