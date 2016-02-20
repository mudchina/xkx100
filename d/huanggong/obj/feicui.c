// feicui.c 翡翠鸡

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(GRN"翡翠鸡"NOR, ({ "stone chicken", "feicui ji", "ji" }));
	set("weight", 5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("value", 80000);
		set("long", "一对翡翠鸡，一公母，雕工极是精细。\n");
		set("material", "stone");
	}
	setup();
}
