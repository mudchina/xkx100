// /kungfu/class/taohua/bagua.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(GRN"铁八卦"NOR, ({ "tie bagua", "bagua" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","铁八卦是纯铁所铸，分量极重，上有八卦图案。\n是桃花岛弟子用来占卜、推算(location)他人区位的道具。\n");
		set("unit", "枚");
		set("value", 1600);
	}
	setup();
}
