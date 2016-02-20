// shigu.c
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("石鼓", ({ "shi gu", "gu" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", "这是一个很古朴的石鼓，江南书香门第中的爱物。\n");
		set("value", 100);
		set("material", "stone");
		set("no_get",1);
		set("no_drop",1);
	}
	setup();
}

