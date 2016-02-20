// ironstone.c
inherit ITEM;
#include <ansi.h>
inherit F_UNIQUE;

void create()
{
	set_name(HIB"铁石"NOR, ({ "iron stone","stone"}));
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long","这是一块陨星铁石，表面烧得焦黑的，看上去坚硬之极。\n似乎是制造兵器的绝好材料。\n");
		set("value", 0);
		set("material", "stone");
	}
}

void owner_is_killed()
{
	destruct(this_object());
}
