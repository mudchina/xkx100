// kuihuazhen.c

#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(HIY"葵花"BLK"针"NOR, ({ "kuihua zhen", "zhen" }) );
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "葵花针是一种专门打制的暗器，外形极薄，杀伤力强。\n");
		set("unit", "束");
		set("base_unit", "根");
		set("base_weight", 1);
		set("base_value", 0);
		set("value", 0);
	}
	setup();
}

