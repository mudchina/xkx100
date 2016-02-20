// jiaohuaji.c 叫化鸡

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("叫化鸡", ({"jiaohuaji", "ji", "chicken"}));
	set_weight(300);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只烤得香喷喷的叫化鸡\n");
		set("unit", "只");
		set("value", 0);
	}
}

