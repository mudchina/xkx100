#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG "Çà²Ë" NOR,({"qingcai"}));
	set_weight(1000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿ðÇà²Ë¡£\n");
                set("unit", "¿ð");
        }
}