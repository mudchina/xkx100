// honghua.c
// Last Modified by winder on Sep. 27 2001

inherit ITEM;

void create()
{
	set_name("无忧红花", ({ "honghua" , "无忧红花"}) );
	set_weight(5);
	set_max_encumbrance(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "朵");
		set("prep", "on");
		set("long", "一朵鲜红的花。\n");
		set("value", 1);
	}
}

