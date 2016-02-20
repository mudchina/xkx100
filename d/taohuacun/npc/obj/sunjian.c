#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG "Ëñ¼â" NOR,({"sunjian"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»´üËñ¼â¡£\n");
                set("unit", "´ü");
        }
}