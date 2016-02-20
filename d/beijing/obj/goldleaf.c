// goldleaf.c

inherit ITEM;

void create()
{
	set_name("金叶", ({ "gold leaf" , "leaf"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "这是一片精美的金叶子。\n");
		set("value", 10000);
	}
	setup();
}

