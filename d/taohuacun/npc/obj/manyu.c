
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(WHT "鳗鱼" NOR,({"manyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一条活蹦乱跳的鳗鱼。\n");
                set("unit", "条");
        }
}