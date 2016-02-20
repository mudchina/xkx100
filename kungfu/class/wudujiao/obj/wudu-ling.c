// wudu-ling.c 五毒令
// Modified by Venus Nov.1997
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIB"五毒令"NOR, ({"wudu ling", "ling"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "面");
		set("long","这一块五毒令，凭此牌弟子可要毒虫。\n");
		set("value", 0);
		set("material", "steel");
	}
}
