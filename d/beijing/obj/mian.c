// mian.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("面", ({ "mian" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的汤面。\n");
		set("unit", "碗");
		set("value", 100);
		set("food_remaining", 2);
		set("food_supply", 25);
	}
    setup();
}

