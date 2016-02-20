// miluozongzi.c 汨罗粽子

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"汨罗粽子"NOR, ({"miluo zongzi", "zongzi"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","这是一只香甜的汨罗粽子。每到端午，这里的百姓都要划龙舟洒粽子，数千年来相沿成俗。\n");
		set("unit", "只");
		set("value", 300);
		set("food_remaining", 15);
		set("food_supply", 20);
	}
}
