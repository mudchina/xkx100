// book-xisui.c
// Last Modified by winder on May. 29 2001

inherit ITEM;

void create()
{
	set_name("洗髓经", ({ "xisui", "shu", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "卷");
		set("long","这是一卷暗红色的破布，里面密密麻麻的画了不少打坐吐呐的姿势。\n");
                set("treasure", 1);
		set("value", 500);
		set("material", "cloth");
	}
}
