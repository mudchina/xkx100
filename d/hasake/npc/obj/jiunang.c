// jiunang.c  大酒囊

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大酒囊", ({"jiunang", "wineskin", "skin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只是草原牧民的大酒囊，里面装满了香辣的马奶酒。\n");
		set("unit", "只");
		set("value", 250);
		set("max_liquid", 400);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "马奶酒",
		"remaining": 10,
		"drunk_apply": 40,
	]));
}
