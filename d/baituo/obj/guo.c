inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("野苹果", ({"ye pingguo","pingguo", "guo" }));
	set_weight(25);
	if (clonep())
	set_default_object(__FILE__);
	else
	{
		set("unit", "个");
		set("long", "这是一个野外生长的青苹果。\n");
		set("food_remaining", 1);
		set("food_supply", 30); 
		setup();
	}
}
