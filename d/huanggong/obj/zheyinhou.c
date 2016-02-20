// zheyinhou.c

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"ÕÚÒõºî"NOR, ({"zheyin hou"}));
	set_weight(700000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¸öÖê»Ê¹¬ÖĞµÄÕä¹óÊ÷Ä¾¡£\n");
		set("unit", "Öê");
		set("no_get", 1);
	}
}

