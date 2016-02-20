// bijian.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name( HIG "碧剑" NOR, ({ "green sword", "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把翠绿色的剑，剑身又细又长。\n");
		set("value", 400);
		set("material", "steel");
	}
	init_sword(15);
	setup();
}
