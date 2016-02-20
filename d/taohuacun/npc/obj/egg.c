#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL "¼¦µ°" NOR,({"egg"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¸ö¼¦µ°¡£\n");
                set("unit", "¸ö");
        }
}