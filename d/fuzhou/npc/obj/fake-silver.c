// fakesilver.c
#include <ansi.h>

inherit ITEM;
void create()
{
	set_name(HIW"白银"NOR, ({"silver", "ingot", "silver_money"}));
	set_weight(2500000);
	set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "白花花的银子，真是人见人爱。不过好象是镖银耶。\n");
		set("unit", "两");
		set("material", "lead");
	}
	setup();
}

