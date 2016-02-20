// Obj: /d/nanshaolin/obj/liao_kao
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <armor.h>

inherit WRISTS;
void create()
{
	set_name( "镣铐", ({ "liao kao", "kao" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "付");
		set("value", 1000);
		set("material", "steel");
		set("armor_prop/armor",0);
		set("shaolin",1);
	}
	set("no_get",1);
	set("no_drop",1);
	setup();
}

int query_autoload()
{
	return 1;
}

void init()
{
	if (environment() == this_player())
	{
		wear();
		add_action("do_fight","fight");
		add_action("do_fight","hit");
		add_action("do_fight","kill");
		add_action("do_fight", "steal");
		add_action("do_dazuo","dazuo");
		add_action("do_dazuo","exercise");
		add_action("do_tuna","tuna");
		add_action("do_tuna","respirate");
		add_action("do_remove","remove");
	}
}

int unequip()
{
	return notify_fail("你不能自已打开镣铐。\n");
}

int do_fight()
{
	object ob = this_player();

	if ((objectp(ob = present("liao kao", ob)) ) )
	{
		write("你现在手脚戴着镣铐，不能跟人动武。\n");
		return 1;
	}
	return 0;
}

int do_dazuo()
{
	object ob = this_player();
	if ((objectp(ob = present("liao kao", ob)) ) )
	{
		write("你现在手脚戴着镣铐，不能做出正确的姿势来打坐。\n");
		return 1;
	}
	return 0;
}

int do_tuna()
{
	object ob = this_player();
	if ((objectp(ob = present("liao kao", ob)) ) )
	{
		write("你现在手脚戴着镣铐，不能做出正确的姿势来吐纳。\n");
		return 1;
	}
	return 0;
}

int do_remove(string arg)
{
	if (!arg) return 0;

	if(arg=="all")
	{
		write("你身上有镣铐，手脚不便利，还是一件件的除吧。\n");
		return 1;
	}
	return 0;
}

