// Room: /d/gumu/obj/box.c 铁盒
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(RED "大铁盒" NOR, ({ "da tiehe", "tiehe", "box" }) );
	set_weight(30000000);
	if( clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个锈迹斑斑的大铁盒子，看来很久没有人动过了。\n");
		set("value", 1000);
		set("material", "steel");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

