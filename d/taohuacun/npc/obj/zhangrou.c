#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY "â¯ÍÈÈâ" NOR,({"zhangrou"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»´ó¿éâ¯ÍÈÈâ¡£\n");
                set("unit", "¿é");
        }
}