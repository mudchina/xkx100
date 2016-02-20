// tjcloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("太监服饰", ({ "taijian cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一件太监服饰，闻起来有一股说不出的恶臭。\n");
		set("unit", "件");
		set("value", 60);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
	}
	setup();
}
