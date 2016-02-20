// Room: /d/huijiang/obj/box.c 宝箱
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"宝箱"NOR, ({ "gold xiang", "xiang", "box" }) );
	set_weight(3000);
	set_max_encumbrance(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long","一个装钱的箱子，红花会从各地劫来的不义之财全放在这里。\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

int is_container() { return 1; }
