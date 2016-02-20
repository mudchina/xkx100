// qishayan.c 漆沙砚

inherit ITEM;

void create()
{
	set_name("漆沙砚", ({"qisha yan", "yan"}) );
	set_weight(100);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","漆沙砚，上有宋宣和内府制六字。其形质类澄沙而绝轻，入水不沉，甚异之。\n");
		set("value", 5000);
		set("unit" , "方");
	}
	setup();
}

	


