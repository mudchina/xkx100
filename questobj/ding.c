// ding.c 神木王鼎

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(YEL"神木王鼎"NOR, ({ "shenmu wangding", "ding" }));
	set_weight(500);
	set("taskobj", 1);
	set("count", 50);
	set_max_encumbrance(1000);
	if (clonep())

		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", 
YEL"这是一座色作深黄的小小木鼎。木鼎雕琢甚是精细，木质坚润似
似玉，木理之中隐隐约约的泛出"RED"红丝"YEL"。鼎侧有五个铜钱大的圆孔，
木鼎齐颈处有一道细缝，似乎分为两截。\n"NOR);
		set("value", 0);
	}
}

int is_container() { return 1; }

void init()
{
}
