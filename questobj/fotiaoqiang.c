// fotiaoqiang.c
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"佛跳墙"NOR, ({"fotiaoqiang"}));
	set("taskobj", 1);
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗香喷喷的佛跳墙，是福建第一名菜。\n");
		set("unit", "碗");
		set("value", 0);
	}
}
