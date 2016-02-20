// bing.c

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("ºì¶¹±ù", ({ "hongdou bing","bing" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»±­ÉÏºÃµÄºì¶¹±ù¡£\n");
		set("unit", "±­");
		set("value", 50);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
	setup();
}
