// tangfan.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("卖糖小贩" , ({ "tang fan", "fan" }) );
	set("gender", "男性" );
	set("age",20);
	set("combat_exp", 15000);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set("attitude", "friendly");
	set("vendor_goods", ({
		FOOD_DIR+"sugar/bingtang",
		FOOD_DIR+"sugar/shuitang",
		FOOD_DIR+"sugar/yuantang",
		FOOD_DIR+"sugar/zaotang",
		FOOD_DIR+"sugar/xitang",
		"/clone/misc/fire",
	}) );
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (environment(ob)==environment())
	message_vision("卖糖的小贩冲$P吆喝着：家里有喜事吗？买点糖果招待朋友吧。\n",ob);
	return;
}
