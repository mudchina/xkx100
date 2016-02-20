// qing-zhuling.c 青竹令
// Modified by Venus Nov.1997
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"青竹令"NOR, ({"qingzhu ling", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "面");
                set("long","这是一块用青竹做成的令牌,由九袋长老简长老签发,凭此牌
弟子可自由向同门大师兄挑战。\n");
                set("value", 0);
                set("material", "steel");
        }
}
