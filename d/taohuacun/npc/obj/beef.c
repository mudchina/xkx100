#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("≈£»‚",({"beef"}));
	set_weight(500);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "“ªøÈ≈£»‚°£\n");
                set("unit", "øÈ");
        }
}