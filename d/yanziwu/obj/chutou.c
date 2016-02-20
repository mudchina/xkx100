// chutou.c
inherit ITEM;

void create()
{
	set_name("锄头", ({ "chu tou" }));
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一把锄地的锄头。\n");
		set("unit", "把");
		set("value", 0);
	}
}

