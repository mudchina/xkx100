// Room: /d/chengdu/obj/box1.c 善缘箱
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("善缘箱", ({ "shanyuan xiang", "xiang", "box" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long","这是一个小庙里常见的箱子，专门用来接受善男信女们的捐款。\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

int is_container() { return 1; }

