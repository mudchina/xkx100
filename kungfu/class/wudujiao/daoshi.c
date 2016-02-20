// daoren.c
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
inherit F_MASTER;
int ask_me();

void create()
{
	set_name("游方道人", ({ "dao ren", "dao", "daoren" }) );
	set("gender", "男性" );
	set("age", 34);
	set("class", "taoist");
	set("long",
		"一个白净矮胖的道士，见谁都笑眯眯的，正悠闲的品着一杯香茶。\n");
	set("max_qi", 2000);
	set("per", 18);
	set("max_jing", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("rank_info/respect", "笑面郎中");
	set_skill("dodge", 80);
	set_skill("unarmed",80);
	set_skill("parry", 80);
	set_skill("force",80);
	set_skill("hammer", 80);
	set_skill("five-poison", 80);
	set_skill("sword",80);
	set_skill("literate", 50);
	set_skill("wudu-yanluobu", 70);
	set_skill("qianzhu-wandushou", 75);
	set_skill("wudu-shengong", 70);

	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("unarmed", "qianzhu-wandushou");
	map_skill("parry", "qianzhu-wandushou");
	set("env/wimpy", 60);
	set("inquiry", ([
	    "五毒教": (: ask_me :),
	]) );
	set("vendor_goods", ({
	       "/d/wudujiao/npc/obj/jiedudan",
	}));
	create_family("五毒教", 13, "护法弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",30);
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
	switch( random(3) ) {
		case 0:
			say( "游方道人嘿嘿一阵奸笑道：这位" + RANK_D->query_respect(ob) + "，也是来住店的吗？\n");
			break;
		case 1:
			say( "游方道人点了点手道：这位" + RANK_D->query_respect(ob) + "请过这里坐，这是要去那啊？\n");
			break;
		case 2:
			say( "游方道人面现惊讶之色道：这位" + RANK_D->query_respect(ob) + "眉现黑气，近日会有大难。\n贫道有一些随身丹丸可以卖给你，或许可救你一命。\n");
			break;
	}
}
void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") == "无性") {
		command("say 这位公公不要开玩笑了。");
		command("say 这位" + RANK_D->query_respect(ob) +
			"还是快去伺候皇上吧！");
		return;
	}

	if ((int)ob->query("shen") > 1000) {
		command("say 做我五毒教弟子必须心狠手辣。");
		command("say 我教弟子贵在随心所欲，不收伪君子");
		return;
	}

	command("recruit " + ob->query("id"));
	return;
}
int ask_me()
{
	object ob,me;
	me = this_player();
	if ((string)me->query("family/family_name") != "五毒教")
	      return notify_fail("对不起，无可奉告！\n");
	command("say 这位"+ RANK_D->query_respect(me)
	       + "来的正好，这里正有马车要回山办事，就让他们送你一程吧。\n");
	 message_vision(HIC"游方道人一招手，一辆马车驶过来停在门前。\n$N急忙钻进车中，只听一阵清脆的鞭响，马车绝尘而去。\n\n"NOR,me);
	ob = load_object("/d/wudujiao/damen");
	ob = find_object("/d/wudujiao/damen");
	message("vision", "远处一辆马车急驶而来，车门一开"+me->query("name")+"从里面钻了出来。\n", ob);
	 tell_object(me, "只听车把势说道：这位"+ RANK_D->query_respect(me) + "已经到了，请下车吧。\n"NOR );
	me->move("/d/wudujiao/damen");
	return 1;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
	ob->set("title",HIY"五毒教徒"NOR);
 				  }
}
