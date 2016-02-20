#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG "虾仁" NOR,({"xiaren"}));
	set_weight(20);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盘新鲜的河虾虾仁。\n");
                set("unit", "盘");
        }
}