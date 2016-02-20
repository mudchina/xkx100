// gelu.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIR "割鹿刀" NOR, ({ "gelu" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "秦失其鹿，天下共逐，唯胜者得鹿而割之－－
唯有天下的第一英雄才能得到的宝刀！\n");
		set("value", 50000);
		set("rigidity",2500);	
		set("material", "steel");
		set("max_enchant",5);
		set("for_create_weapon",1);
	}
	init_blade(30);
	setup();
}
