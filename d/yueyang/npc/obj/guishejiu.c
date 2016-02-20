// guishejiu.c 龟蛇酒壶

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("龟蛇酒壶", ({"guishe jiuhu", "jiu", "jiuhu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装龟蛇酒的酒壶，里面可装一斤的酒。\n");
		set("unit", "个");
		set("value", 300);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "龟蛇酒",
		"remaining": 5,
		"drunk_apply": 3,
	]));
}
