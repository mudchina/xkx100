#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR "公鸡" NOR,({"cock"}));
	set_weight(200);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一只嫩公鸡。\n");
                set("unit", "只");
        }
}