// smith.c
#include "ansi.h"
inherit NPC;
inherit F_DEALER;

string ask_blade();
string ask_sword();
void create()
{
	set_name("铁匠", ({ "tiejiang", "smith" }));
	set("title", "铁匠铺老板");
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long", "铁匠正用铁钳夹住一块红热的铁块放进炉中。\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
		"/kungfu/class/dali/obj/axe",
		"/d/city/obj/changjian",
		"/d/city/obj/hammer",
		"/d/beijing/obj/tudao",
		"/d/city/obj/dagger",
		"/d/xingxiu/obj/tiegun",
		"/d/city/obj/gangdao",
		"/d/city/npc/obj/tiejia",
	}));
	
	set("inquiry", ([
	    "宝剑": (: ask_sword :),
            "宝刀": (: ask_blade :),
	]) );
	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

int accept_object(object who, object ob)
{
	object weapon;
	object me = this_player();
		
	if (ob->query("money_id") && ob->value() >= 3000000) 
	{
		if(me->query_temp("blade_temp"))
		
		{
		weapon = new("/d/city/npc/obj/baodao",1);
		weapon ->move(me);
		me->delete_temp("blade_temp");
		}
		else if(me->query_temp("sword_temp"))
		{
		weapon = new("/d/city/npc/obj/baojian",1);
		weapon ->move(me);
		me->delete_temp("sword_temp");
		}
		else return 1;
		message_vision(HIY"铁匠掏出一把金光闪闪的兵器给你\n"NOR,who);
		
	
	}	
			

	return 1;

}

string ask_blade()
{
	object me=this_player();
	me->set_temp("blade_temp",1);
	return "宝刀是有，就看你出得起价钱么......\n";
	
}


string ask_sword()
{
	object me=this_player();
	me->set_temp("sword_temp",1);
	return "宝剑是有，就看你出得起价钱么......\n";
}

/*
int buy_object(object who, string what)
{
	if( what=="hammer" ) return 300;
	if( what=="changjian" ) return 700;
	return 0;
}

void compelete_trade(object who, string what)
{
	object ob;

	if( what=="hammer" ) ob = new(__DIR__"obj/hammer");
	if( what=="changjian" ) ob = new(__DIR__"changjian");
	ob->move(who);
	if( what=="hammer" )
message_vision("$N交给$n一把沈甸甸的打铁用铁锤。\n", this_object(), who);
	if( what=="changjian" )
message_vision("$N交给$n一把青光闪闪的长剑。\n", this_object(), who);
}
*/
