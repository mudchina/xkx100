// yinzhencha.c 君山银针茶

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW"君山银针茶"NOR, ({"junshan yinzhencha", "yinzhen", "cha"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一碗君山银针茶，白白的针尖般的茶叶在沸水中竖直而立，美妙非常。\n");
		set("unit", "碗");
		set("value", 200);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "tea",
		"name": "君山银针茶",
		"remaining"  : 5,
		"drunk_apply": 2,
	]));
}
