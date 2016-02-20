// yangfr.c

inherit ITEM;
void create()
{
	set_name("阳夫人遗骨", ({ "yang furen corpse" }) );
	set_weight(30000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具" );
		set("long", "这是一具明教前任教主阳顶天夫人的遗骨。她胸口插着一口精亮的匕首。\n");
	}
	setup();
}

