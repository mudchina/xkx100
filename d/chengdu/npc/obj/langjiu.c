// langjiu.c 郎酒瓶

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("郎酒", ({"lang jiu", "langjiu", "jiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一瓶郎酒，大概装得两斤的酒。\n");
		set("unit", "个");
		set("value", 200);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "郎酒",
		"remaining": 5,
		"drunk_apply": 3,
	]));
}
