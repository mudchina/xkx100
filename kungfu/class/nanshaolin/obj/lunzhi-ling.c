// Last Modified by Winder on May. 29 2001
// lunzhi-ling
inherit ITEM;

void create()
{
	set_name( "轮值令", ({ "lunzhi ling", "ling", "iron" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块用于南少林轮值用的令牌。\n");
		set("value", 100);
		set("material", "iron");
	}
	setup();
}

void init()
{
	call_out("dest", 900);
}

void dest()
{
	destruct(this_object());
}
