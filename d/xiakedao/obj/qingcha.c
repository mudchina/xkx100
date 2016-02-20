// qingcha.c 清茶

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("清茶",({"tea", "cha", "qing cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一杯热茶，悠悠地冒着香气～～～\n");
		set("unit", "杯");
		set("value", 1000);
		set("max_liquid", 20);
	}
	set("liquid", ([
		"type": "tea",
		"name": "茶",
		"remaining": 2,
		"drunk_apply": 25,
	]));
}
