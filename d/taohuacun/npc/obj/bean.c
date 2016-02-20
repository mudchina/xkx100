#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(CYN "¶¹°ê" NOR,({"bean"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Àº¶¹°ê¡£\n");
                set("unit", "Àº");
        }
}