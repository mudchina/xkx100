// guanyin.c

inherit ITEM;

void create()
{
	set_name("观音石", ({ "guanyin shi","guanyin", "shi" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个亭亭玉立的石人，活象一尊古装仕女，人称观音石。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }

