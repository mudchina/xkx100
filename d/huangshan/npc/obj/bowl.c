// bowl.c

inherit ITEM;

void create()
{
	set_name("饭钵", ({ "bowl" }) );
	set_weight(5000);
	set_max_encumbrance(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个和尚用的饭钵\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
