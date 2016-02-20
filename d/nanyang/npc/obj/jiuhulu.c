// Room: /d/nanyang/npc/obj/jiuhulu.c
// Last Modified by winder on Nov. 20 2001
//这是用来买酒用的葫芦，不是common装备用的，所以比较贵。

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
	set_name(YEL"酒葫芦"NOR, ({"jiu hulu", "hulu", "pot"}));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装酒的大葫芦，外皮金黄，里面能装好几斤酒。\n");
		set("unit", "个");
		set("value", 300);
		set("max_liquid", 30);
	}
	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "黄酒",
		"remaining": 30,
		"drunk_apply": 10,
	]));
}

