// Obj: /d/lingxiao/obj/yupai.c 寒玉牌
// Last Modified by winder on Jul. 15 2001

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW"寒玉牌"NOR, ({"hanyu pai", "pai"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long","这是一块雪白的玉牌，触手生寒，凝人气血。\n");
		set("material", "yu");
	}
}

