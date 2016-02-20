#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG "∫…“∂" NOR,({"heye"}));
	set_weight(10);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "“ª∆¨∫…“∂°£\n");
                set("unit", "∆¨");
        }
}