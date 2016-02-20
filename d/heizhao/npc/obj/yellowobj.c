// item: yellowobj.c

inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"黄布小囊"NOR, ({"huangbu xiaonan", "xiaonan"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一只黄布小囊，不知道有什么用处。\n");
                set("unit", "只");
                set("value", 1);
        }
}

