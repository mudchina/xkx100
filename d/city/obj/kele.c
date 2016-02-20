// wineskin.c  酒袋

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("可乐", ({"ke le", "ke", "le"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一杯放了冰块的可乐。\n");
		set("unit", "杯");
		set("value", 20);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "",
		"remaining": 15,
		"drunk_supply": 6,
	]));
}

