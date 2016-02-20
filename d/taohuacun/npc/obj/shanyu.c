#include <ansi.h>
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("鳝鱼",({"shanyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一条活蹦乱跳的鳝鱼。\n");
                set("unit", "条");
        }
}