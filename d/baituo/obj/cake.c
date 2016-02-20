//dangao.c
inherit F_FOOD;
inherit ITEM;
void create()
{
	set_name("µ°¸â", ({ "cake" }) );
	set_weight(200);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éÏãÅçÅçµÄ´óµ°¸â¡£\n");
		set("unit","¿é");
		set("value",200);
		set("food_remaining",4);
		set("food_supply",20);
	}
	setup();
}
