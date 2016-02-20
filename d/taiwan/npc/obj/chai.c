// chai.c
// Last Modifyed by Ahda on Jan. 4 2002

inherit ITEM;
void create()
{
	set_name( "Ä¾²ñ", ({ "mu chai"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "À¦");
		set("long","ÕâÊÇÒ»À¦Ä¾²ñ¡£\n");
		set("value", 0);
		set("material", "wood");
	}
}
