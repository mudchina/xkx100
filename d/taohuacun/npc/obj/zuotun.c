#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "Ñò¸á×øÍÎ" NOR,({"zuotun"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿éÑò¸á×øÍÎ¡£\n");
                set("unit", "¿é");
        }
}