#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "百合" NOR,({"baihe"}));
	set_weight(10);
	set("value", 100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一束盛开的百合花。\n");
                set("unit", "束");
        }
}