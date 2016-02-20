// yellowcloth.c
// Last Modified by winder on May. 25 2001

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(YEL"»Æ¸ð¶ÌÉÀ"NOR, ({"yellow cloth", "cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", YEL"Ò»¼þ»Æ¸ð¶ÌÉÀ¡£\n"NOR);
		set("material", "cloth");
		set("unit", "¼þ");
		set("value", 400);
		set("armor_prop/armor", 5);
		set("armor_prop/personality", 1);
	}
	setup();
}

