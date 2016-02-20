#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG "霜小画" NOR,({"ljcha"}));
	set_weight(50);
	set( "value", 10000 );
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "匯期霜小画匐。\n");
                set("unit", "期");
        }
}