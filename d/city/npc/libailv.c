// npc: /d/city/npc/libailv.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name( YEL "李百履" NOR , ({ "li bailv","li","bailv" }) );
	set("age", 43);
	set("title", "李家丝鞋铺老板");
	set("long", @LONG
李百履是一条瘦小的汉子，他五短身材，但是却很有精神。从眼睛里就
能看出这是个精明的生意人。他就是这家鞋店的老板。
LONG
	);
	set("chat_chance", 40);
	set("chat_msg", ({
		"李老板道：这里就是扬州城啦，有名的花花世界啊！\n",
		"李老板道：说起本府的程老爷，那是天下一等一的大才子，有学问！\n",
		"李老板道：嘿嘿，客官，您别光说话聊天啊，照顾照顾小老儿的生意啊？\n",
		"李老板道：客官，您瞧瞧，这双丝鞋多合适啊。您家试试，来我帮您包上，怎么样？\n",
	}));
	set("inquiry", ([
		"丝鞋" : "啊，您要买丝鞋是吧？没问题，咱家的鞋是扬州城里头一份！\n",
		"here" : "这扬州城啊，那是大江南北头一个繁华的去处！\n",
	]) );
	set("vendor_goods", ({
		BOOT_DIR+"maxie",
		BOOT_DIR+"pixue",
		BOOT_DIR+"sifeng_huangxue",
		BOOT_DIR+"sifeng_kuanxue",
		BOOT_DIR+"sixie",
		BOOT_DIR+"baodi_kuaixue",
		BOOT_DIR+"xiuhua_xie2",
		BOOT_DIR+"zihua_xie",
		BOOT_DIR+"gongxie",
		BOOT_DIR+"caoxie",
	        BOOT_DIR+"flower_shoe",
	}) );

	set("attitude", "friendly");
	set("rank_info/respect", "老哥");
	set("rank_info/rude","老王八蛋");
	set("combat_exp",100);
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
	message_vision( "李老板热情的迎上来：“客官，您买双鞋？哎，不买不要紧，看看货色么。”\n",ob);
	return;
}
