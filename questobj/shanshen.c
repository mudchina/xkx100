// shanshen.c 老山参

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
}

void create()
{
	set_name(YEL"老山参"NOR, ({"laoshan shen", "shen"}));
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "这是一株沾满山泥的长白老山参。\n");
		set("value", 0);
	}
	setup();
}

