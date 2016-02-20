// Room: /d/nanyang/npc/boss.c
// Last Modified by winder on Nov. 20 2001

#include <ansi.h>

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("樊子发", ({ "fan zifa","fan","seller"}) );
	set("gender", "男性" );
	set("age", 46);
	set("long", "樊子发是这间小商号的老板，写得一手好字。\n");
	set("chat_chance", 20);
	set("chat_msg", ({
		"樊子发道：“这里是南阳城。”\n",
		"樊子发道：“南阳城北接中原，南渡汉水，客官想去哪里呀？”\n",
	}));
	set("chat_chance_combat", 20);
	set("chat_msg_combat",({
		"樊子发喊道：“你干什么？如此无理？！！！”\n",
		"樊子发边打边喊：“我可是嵩山派的红人，你竟敢杀我？！！！”\n",
	}) );
	set("inquiry", ([
		"here"   : "这里是南阳城，南阳诸葛祠，天下闻名耶！",
	]) );
	set("attitude", "friendly");
	set("rank_info/respect", "老哥");
	set("rank_info/rude","老王八蛋");
	set("vendor_goods", ({
		__DIR__"obj/zheshan",
		__DIR__"obj/jiuhulu",
		__DIR__"obj/jiutan",
		__DIR__"obj/xianbing",
	}) );
	set("combat_exp",100);
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
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
	if( !ob || environment(ob) != environment() ) return;
	message_vision("樊老板笑嘻嘻地迎上前来，说道：“客官，您来啦？”\n",ob);
}
