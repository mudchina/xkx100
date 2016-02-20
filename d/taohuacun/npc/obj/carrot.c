
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR"ºúÂÜ²·"NOR,({"carrot","huluobo"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»ÀººúÂÜ²·¡£\n");
                set("unit", "Àº");
        }
}