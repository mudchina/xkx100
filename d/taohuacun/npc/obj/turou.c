#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "ÍÃÈâ" NOR, ({"turou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éÏÊÑªÁÜÀìµÄÒ°ÍÃÈâ¡£\n");
		set("unit", "¿é");
	}
}
