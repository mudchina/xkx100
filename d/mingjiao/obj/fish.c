// fish.c

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("大白鱼", ({ "fish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一尾大白鱼，长达一尺。\n");
		set("unit", "尾");
		set("value", 30);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("material", "bone");
	}
	setup();
}

int finish_eat()
{
	set_name("鱼骨", ({ "fish bone" }) );
	set_weight(150);
	set("long", "一根啃得精光的鱼骨头，看样子可以作针。\n");
	return 1;
}
