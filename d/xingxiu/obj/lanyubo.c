// lanyubo.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIB"蓝玉钵"NOR,({ "lanyu bo", "bo" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "一只蓝田美玉精制而成的药钵，虽然使用日久, 但丝毫没有破痕。药钵里残留了微量剧毒, 然已足够毒死偷宝之人。\n");
		set("value", 20000);
	}
	setup();
}
