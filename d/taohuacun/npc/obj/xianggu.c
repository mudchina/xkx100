#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT "香菇" NOR,({"xianggu"}));
	set_weight(200);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一袋刚采摘下来的香菇。\n");
                set("unit", "袋");
        }
}