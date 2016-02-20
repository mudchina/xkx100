// 18niou.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"十八泥偶"NOR, ({ "18 niou", "niou" }));
	set_weight(600);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "盒");
		set("long", 
"这是一个小木盒，盒中垫着棉花，并列着三排泥制玩偶，每排六
个，共是一十八个。玩偶制作精巧，每个都是裸体的男人，皮肤
上涂了白垩，画满了一条条红线，更有无数黑点，都是脉络和穴
道的方位。\n");
		set("value", 0);
		set("material", "mud");
	}
}

