// hougan.c ºï¸Î
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ºï¸Î", ({ "hou gan", "gan" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¿Å");
		set("long", "ÕâÊÇÒ»¿Å×ÏºÚÉ«µÄºï¸Î¡£\n");
		set("value", 1000);
		set("medicine", 1);
	}
	setup();
}
