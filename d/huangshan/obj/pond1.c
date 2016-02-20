// pond1.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"赤池"NOR, ({ "chi chi", "chi" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", HIR"一个水色为赤的池潭。\n"NOR);
                set("value", 1);
        }
}

int is_container() { return 1; }

