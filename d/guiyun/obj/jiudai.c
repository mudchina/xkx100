// Obj: /d/guiyun/obj/jiudai.c
// Last Modified by winder on Jul. 9 2001

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("皮酒袋", ({"jiudai"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装甜酒的大酒袋，大概装得四、五升的酒。\n");
		set("unit", "个");
		set("value", 60);
		set("max_liquid", 10);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "甜酒",
		"remaining": 10,
		"drunk_apply": 3,
	]));
}
