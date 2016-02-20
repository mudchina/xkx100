#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL "小牛腰子" NOR,({"yaozi"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个小牛腰子。\n");
                set("unit", "个");
        }
}