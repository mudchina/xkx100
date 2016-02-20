// npc: /d/city/npc/libailv.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name( YEL "彭宝现" NOR, ({ "peng baoxian","peng","baoxian" }) );
	set("gender", "男性" );
	set("title", "彭记鲜果店老板");
	set("age", 49);
	set("attitude", "friendly");
	set("rank_info/respect", "老哥");
	set("rank_info/rude","老王八蛋");
	set("long", @LONG
彭老板的这家彭记鲜果店在扬州城也是颇有名气，来采买果品的顾客很
多，以致于人手总是很紧张，这不，连老板都亲自上阵了。老彭一边给
一个顾客算帐，一边回答另外一个顾客的问讯，还不时回头对伙计吩咐
些什么。
LONG);
	set("chat_chance", 30);
	set("chat_msg", ({
		"彭老板道：怎么样？客官，不来二斤桃子尝尝么？\n",
		"彭老板道：来啊客官，这西瓜不甜不要钱！\n",
		"彭老板道：您等等，我这儿忙完了就过来。\n",
		"彭老板：瞧一瞧罢，客官，连知府老爷家的果品都是小店供应的。\n",
	}));
	set("inquiry", ([
		"鲜果" : "啊，是啊是啊，小店各种鲜果应有尽有，看看吧！",
		"here" : "咦！您家看了，「彭记鲜果铺」这大招牌不是明摆着的么？",
	]) );
	set("vendor_goods", ({
		FRUIT_DIR+"banana",
		FRUIT_DIR+"banli",
		FRUIT_DIR+"boluo",
		FRUIT_DIR+"caomei",
		FRUIT_DIR+"foshou",
		FRUIT_DIR+"ganzhe",
		FRUIT_DIR+"guiyuan",
		FRUIT_DIR+"hamigua",
		FRUIT_DIR+"hetao",
		FRUIT_DIR+"hongzao",
		FRUIT_DIR+"juzi",
		FRUIT_DIR+"lemon",
		FRUIT_DIR+"laiyangli",
		FRUIT_DIR+"lizhi",
		FRUIT_DIR+"lizi",
		FRUIT_DIR+"mangguo",
		FRUIT_DIR+"pipa",
		FRUIT_DIR+"putao",
		FRUIT_DIR+"shiliu",
		FRUIT_DIR+"shizi",
		FRUIT_DIR+"taozi",
		FRUIT_DIR+"xianggua",
		FRUIT_DIR+"xigua",
		FRUIT_DIR+"xingzi",
		FRUIT_DIR+"yali",
		FRUIT_DIR+"yangmei",
		FRUIT_DIR+"yingtao",
	}) );
	set("combat_exp", 10000);
	set_skill("unarmed", 22);
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}

void init()
{
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision("彭老板大声吆喝道：“时新鲜果，样样都有，价钱公道，童叟无欺！”\n",ob);
	return;
}
