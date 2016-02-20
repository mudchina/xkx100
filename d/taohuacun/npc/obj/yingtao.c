#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"Ó£ÌÒ"NOR,({"yingtao"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»´üÏÊºìµÄÓ£ÌÒ¡£\n");
                set("unit", "´ü");
        }
}