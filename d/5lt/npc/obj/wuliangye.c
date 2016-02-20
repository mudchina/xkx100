// Room: /d/chengdu/npc/obj/wuliangye.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("五粮液", ({"wuliangye", "wu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一瓶刚刚打开的五粮液，酒香扑鼻，让人垂涎三尺。\n");
		set("unit", "瓶");
		set("value", 300);
		set("max_liquid", 15);
	}
	set("liquid", ([
		"type": "alcohol",
		"name": "五粮液",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}

