// qiyunao.c
// 齐云敖
// by star
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("齐云敖", ({ "qi yunao", "qi" }));
	set("nickname", HIG "锦衣毒丐" NOR);
	set("long",@LONG
他就是五毒教的长老，人称锦衣毒丐的齐云敖。乃是教主的同门师兄，在教中
一向飞扬跋扈，大权独揽。他长的身材魁梧，面目狰狞，身穿一件五彩锦衣，太阳
穴高高坟起。
LONG
	);
	set("title","五毒教长老");
	set("gender", "男性");
	set("class", "shaman");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("per", 12);
	set("int", 20);
	set("con", 30);
	set("dex", 20);
	set("max_qi", 4000);
	set("max_jing", 4000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 170);
	set_skill("wudu-shengong", 170);
	set_skill("dodge", 160);
	set_skill("wudu-yanluobu", 220);
	set_skill("hand", 200);
	set_skill("qianzhu-wandushou", 300);
	set_skill("strike", 200);
	set_skill("wudu-zhang", 300);
	set_skill("parry", 200);
	set_skill("sword", 170);
	set_skill("hook", 170);
	set_skill("wudu-goufa", 250);
	set_skill("qingmang-sword", 250);
	set_skill("five-poison", 150);
	set_skill("literate", 80);
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("hand", "qianzhu-wandushou");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-goufa");
	map_skill("sword", "qingmang-sword");
	map_skill("hook", "wudu-goufa");
	prepare_skill("hand", "qianzhu-wandushou");
	prepare_skill("strike", "wudu-zhang");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "hook.suo" :),
		(: perform_action, "hand.qzwd" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("五毒教", 11, "长老");
	set("jinshe_count", 1);
	set("chat_chance",5);
	set("chat_msg",({
		"齐云敖怒道：这贱婢这样下去，本教三祖七子辛苦创下的基业都要毁在她手里了。\n",
		"齐云敖自言自语道：我如能找到天下最厉害的毒圣，这教主之位就是我的了。\n",
	}));
	setup();

	carry_object("/d/wudujiao/npc/obj/jinshechui")->wield();
	carry_object("/d/wudujiao/npc/obj/jinyi")->wear();
	carry_object("/clone/book/poisonbook2");

	add_money("silver",10);
}

void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") == "无性")
	{
		command("say 这位公公不要开玩笑了。");
		command("say 这位" + RANK_D->query_respect(ob) + "还是快去伺候皇上吧！");
		return;
	}

	if ((int)ob->query("shen") > -10000)
	{
		command("say 做我五毒教弟子必须心狠手辣。");
		command("say 这位" + RANK_D->query_respect(ob) + "心慈手软，可惜与我教没有缘分啊！");
		return;
	}

	if ((string)ob->query("family/family_name") != "五毒教")
	{
		command("say 这位" + RANK_D->query_respect(ob) + "不是本教弟子，还是请回吧！");
		return;
	}

	if ((int)ob->query_skill("five-poison", 1) < 100)
	{
		command("say 我五毒教弟子以毒杀人，修习毒技是首要的。");
		command("say 这位" + RANK_D->query_respect(ob) +
			"是否还应该多多钻研本门的绝学？");
		return;
	}
	if ((int)ob->query_skill("wudu-shengong", 1) < 100)
	{
		command("say 你的五毒神功还学的不够啊。");
		return;
	}

	command("chat 嘿嘿嘿嘿！！！！！");
	command("chat 该当我五毒教发扬光大，称霸武林指日可待了。");
	command("chat 嘿嘿嘿嘿！！！！！");
	command("recruit " + ob->query("id"));

	ob->set("title",HIY"五毒教护法"NOR);
	return;
}
int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if ( (string)ob->query("name") != HIC "龙涎香" NOR )
		return notify_fail("齐云敖摇头道：这些破烂东西给我有什么用啊？\n");
	message_vision("齐云敖见是龙涎香，大喜道：这、这就是龙涎香吗？真是太好了！\n",who);
//	destruct(ob);
	obn=new("/d/wudujiao/npc/obj/jinsheduye");
	obn->move(who);
	message_vision("\n齐云敖说道：本长老不能白收你的东西，这是一瓶金蛇毒液，送给你吧！\n",who);
	return 1;
}

