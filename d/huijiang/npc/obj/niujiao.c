// Room: /d/huijiang/npc/obj/niujiao.c
// Last Modified by winder on Sep. 12 2001
inherit ITEM;

void create()
{
	set_name("金牛角", ({"niu jiao"}));
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "一支牛角，闪着点点金光。\n");
		set("unit", "支");
		set("value", 1000);
	}
}


