//  instrument: dongbula.c
// Jay 3/18/96

#include <ansi.h>
inherit ITEM;
int do_play(string arg);

void init()
{
}

void create()
{
	set_name(HIG"冬不拉"NOR, ({"dongbula"}));
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把维吾尔族的弦乐器冬不拉。你可以演奏(play)它。\n");
		set("value", 0);
	}
//	setup();
}
