// stone3.c

inherit ITEM;
void create()
{
	set_name("岩石", ({ "yan shi", "rock", "yanshi" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块横卧山麓，左厚右薄中空，
状如古琴的岩石。泉水冲击在岩石上，发出悦耳而有节奏的音响。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }

