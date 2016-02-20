//Edited by fandog, 02/15/2000

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("老板娘", ({ "laoban niang", "woman", "boss" }));
	set("title", HIY"老通城第五代传人"NOR);
	set("nickname", HIW"汉口一宝"NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
	set("age", 25);
	set("long","一位年轻女人，略施脂粉，别有一番风韵，她正在灶台上忙活着，一边还招呼着客人。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/jiangling/obj/dongdoufu",
		"/d/jiangling/obj/doupi",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	switch(random(2)) {
	case 0 :
		say("老板娘笑眯眯地说道：这位" + RANK_D->query_respect(ob) + "，快请进来喝杯热茶唦。\n");
		break;
	case 1 :
		say("老板娘说道：哟！这位" + RANK_D->query_respect(ob) + "您喫么事？本店有刚煎好的豆皮，香喷喷的唦。\n");
		break;
	}
}
