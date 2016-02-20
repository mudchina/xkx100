//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"木盒"NOR, ({"mu he", "box"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", YEL"这木盒古朴典雅，沉甸甸的，里面也许有什么宝贵的物事。\n"NOR);
		set("unit", "个");
		set("open_count", 0);
		set("weight", 20000);
	}
}

void init()
{
	add_action("do_open","open");
}

int do_open()
{
	return notify_fail("木盒已经被别人打开过了。\n");
}
