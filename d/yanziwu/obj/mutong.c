// murong.c
inherit ITEM;

void create()
{
	set_name("木桶", ({ "mu tong" }));
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一只浇花的木桶。\n");
		set("unit", "只");
		set("value", 0);
	}
}

