// bing2.c

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("ºì¶¹±ı", ({ "hongdou bing2","bing2"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿é¸Õ³öÂ¯£¬ÈÈÆøÌÚÌÚµÄºì¶¹±ı¡£\n");
		set("unit", "¿é");
		set("value", 100);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
	setup();
}
