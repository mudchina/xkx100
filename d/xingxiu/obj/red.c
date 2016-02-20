// Room: /d/xingxiu/obj/red.c
// Last Modified by winder on Apr. 25 2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"红货"NOR, ({"prize"}));
	set("unit", "包");
	seteuid(getuid());
	set("long","一包从来往商队那里抢来的红货，拿给黯然子应该就可以得到奖励了。\n");
	set("value", 0);
	setup();
}

