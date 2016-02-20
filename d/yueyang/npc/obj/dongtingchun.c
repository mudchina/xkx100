// dongtingchun.c ∂¥Õ•¥∫≤Ë

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIG"∂¥Õ•¥∫≤Ë"NOR, ({"dongtingchun cha", "cha", "tea"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "“ªÕÎ∂¥Õ•¥∫≤Ë£¨»»∫ı∫ıµÿ√∞◊≈“ªπ…≤Ëœ„Œ∂°£\n");
		set("unit", "ÕÎ");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "tea",
		"name": "∂¥Õ•¥∫≤Ë",
		"remaining"  : 5,
		"drunk_apply": 2,
	]));
}
