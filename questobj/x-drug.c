// x-drug.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIB"阴"HIR"阳"HIG"和合散"NOR, ({ "yin yang san", "x-drug" }) );
	set_weight(80);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一种强烈的春药。\n");
		set("unit", "包");
		set("value", 0);
	}
}

