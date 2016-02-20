// Last Modified by Winder on May. 15 2001
// /d/suzhou/npc/obj/diggertools.c

inherit ITEM;

void create()
{
	set_name("盗墓工具", ({ "tools", "daomu gongju", "gravedigger tools"}));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "套");
		set("long", "这是一套专门用来盗墓的工具。干的时候小心点，别让巡捕抓到！\n");
		set("value", 1);
		set("material", "steel");
	}
	setup();
}
