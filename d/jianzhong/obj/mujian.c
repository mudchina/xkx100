#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
       set_name("木剑", ({ "mu jian", "jian", "sword" }) );
       set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	       set("unit", "把");
       	set("long",HIC@LONG
这把剑轻飘飘的浑似无物，是木头削成的，剑身剑柄都有些腐朽了。
LONG
NOR
);
       	set("value", 0);
       	set("material", "wood");
		}
       init_sword(10);
      	setup();
}
