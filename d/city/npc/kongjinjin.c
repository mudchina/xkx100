// npc: /d/city/npc/gubancheng.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name( YEL "孔进金" NOR, ({ "kong jinjin","kong","jinjin" }) );
	set("gender", "男性" );
	set("title", "孔家头巾铺老板");
	set("age", 47);
	set("long", @LONG
孔进金孔老板开了这家头巾铺已经有好几年了，颇受大家的好评，他的
生意也越做越大，可是他却不享清福，仍然亲自站柜台，招呼生意。这
样既省了人手又可以监视伙计们，让他们没有偷懒的机会。
LONG
    );
	set("attitude", "friendly");
	set("rank_info/respect", "老哥");
	set("rank_info/rude","老王八蛋");
	set("combat_exp",100);
	set("inquiry", ([
		"头巾":"哎，一看您就是有眼光的主儿，要不怎么想买咱家的头巾呢？\n",
		"here":"哎哟，客官，您是头回来扬州吧？好好转转吧。\n",
	]) );
	set("chat_chance", 40);
	set("chat_msg", ({
		"孔老板道：哟，客官，一看您就是练武的人，练武人戴块青色头巾最好了。\n",
		"孔老板道：客官，您听说没有，大理的段王爷出钱开通了到大理的马车。\n",
		"孔老板道：来，客官，选一块喜欢的头巾吧，我给您打个九五折怎么样？\n",
		"孔老板道：呵呵，客官，您要是不买您就多看看货色，我这儿还忙着呢。\n",
	}));
	set("vendor_goods", ({
		HEAD_DIR+"damao",             
		HEAD_DIR+"mabutoujin",       
		HEAD_DIR+"nuanmao",           
		HEAD_DIR+"qingshajin",       
		HEAD_DIR+"sanshanmao",       
		HEAD_DIR+"wanzijin",         
		HEAD_DIR+"yizijin",          
		HEAD_DIR+"zaoshahuajin",     
		HEAD_DIR+"zhanmao",           
	}) );
	set_skill("unarmed", 5);
	setup();
	carry_object( "/clone/cloth/male-cloth")->wear();
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
	message_vision( "孔老板见有人进来，连忙吆喝：“瞧一瞧，看一看，咱家的头巾真不赖！”\n",ob);
	return;
}
