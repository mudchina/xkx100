#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "°×²Ë" NOR,({"baicai"}));
	set_weight(1000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿ð°×²Ë¡£\n");
                set("unit", "¿ð");
        }
}