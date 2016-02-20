// ren.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("任我行", ({ "ren woxing", "ren","woxing" }));
	set("long", "只见他一张长长的脸孔，脸色雪白，更无半分血色，眉目清秀，
身材甚高，一头黑发，穿的是一袭青衫。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("no_get", 1);
	set("bihua", 10);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
 	set("jiali", 400);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 100);         // 读书识字
	set_skill("force", 200);            // 基本内功
	set_skill("finger", 200);           // 基本指法
	set_skill("unarmed", 200);          // 基本拳脚
	set_skill("dodge", 200);            // 基本躲闪
	set_skill("parry", 200);            // 基本招架
	set_skill("dagger", 200);           // 基本刺法
	set_skill("sword", 200);            // 基本剑法
        set_skill("shigu-bifa", 200);       // 石鼓打穴笔法
	set_skill("piaoyibu", 200);         // 飘逸步法
	set_skill("wuyun-jian", 200);       // 五韵七弦剑
	set_skill("xuantian-zhi", 200);     // 玄天无情指
	set_skill("kuihua-xinfa", 200);     // 葵花心法
	set_skill("xixing-dafa", 200);      // 吸星心法
	set_skill("changquan", 200);        // 太祖长拳
	set_skill("damo-jian", 200);        // 达摩剑法
	set_skill("taiji-jian", 200);       // 太极剑法
	set_skill("huifeng-jian", 200);     // 回风拂柳剑
	set_skill("taishan-sword", 200);    // 泰山剑法
	set_skill("hengshan-jian", 200);    // 恒山剑法
	set_skill("hengshan-sword", 200);   // 衡山剑法
	set_skill("huashan-sword", 200);    // 华山剑法
	set_skill("songshan-sword", 200);   // 嵩山剑法

	map_skill("force", "xixing-dafa");
	map_skill("sword", "wuyun-jian");
	map_skill("dagger", "shigu-bifa");
	map_skill("finger", "xuantian-zhi");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "damo-jian");
	prepare_skill("finger", "xuantian-zhi");

        set("inquiry", ([
                "比剑" :  (: ask_bijian :),
                "剑法" :  (: ask_bijian :),
                "黑木令" : "要拿黑木令？老夫想先看看你的剑法！\n",
		"日月神教" : "你想加入我日月神教，就得找四大堂长老。",
		"入教"     : "你想加入我日月神教，就得找四大堂长老。",
	]) );

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIW"第七代教主"NOR);
	create_family("黑木崖", 7, "弟子");
 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

int ask_bijian()
{
	object weapon, obj, me = this_player(), ob = this_object();
	int i;

        if (!objectp(weapon = ob->query_temp("weapon")))
	{
		weapon = new("/clone/weapon/changjian");
		weapon -> move(ob);
		command("wield sword");
	}
	if(query("bihua") < 0)
	{
		message_vision("$N躬身说道：“晚辈今日有幸拜见任老前辈，还望多加指教。”\n$n冷笑道：“江南四狗怎么不敢进来见我？！”\n", me, ob );
		return 1;
	}
	add("bihua", -1);
	message_vision("$N躬身说道：“晚辈今日有幸拜见任老前辈，还望多加指教。”\n$n笑道：“不用客气，你来解我寂寞，可多谢你啦。”\n", me, ob );
	message_vision("$N道：“不敢。”\n$n点了点头，说道：“我只想瞧瞧你的剑法，并非真的过招，再说，我也未必能胜得了你。”\n\n", me, ob);
        command("xkx 老子剑法天下第一，找我比剑？找死!");
	command("enable sword damo-jian");
	say(HIR"任我行大喝一声：“少林剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才一招。”\n");
		return 1;
	}
	command("enable sword taiji-jian");
	say(HIR"任我行大喝一声：“武当剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才两招。”\n");
		return 1;
	}
	command("enable sword huifeng-jian");
	say(HIR"任我行大喝一声：“峨嵋剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才三招。”\n");
		return 1;
	}
	command("enable sword songshan-sword");
	say(HIR"任我行大喝一声：“嵩山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才四招。”\n");
		return 1;
	}
	command("enable sword taishan-sword");
	say(HIR"任我行大喝一声：“泰山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才五招。”\n");
		return 1;
	}
	command("enable sword huashan-sword");
	say(HIR"任我行大喝一声：“华山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才六招。”\n");
		return 1;
	}
	command("enable sword hengshan-sword");
	say(HIR"任我行大喝一声：“衡山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“才七招。”\n");
		return 1;
	}
	command("enable sword hengshan-jian");
	say(HIR"任我行大喝一声：“恒山剑法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行叹了口气，说道：“还是没过八招。”\n");
		return 1;
	}

	obj = new("/d/heimuya/obj/heimu-ling");
	obj -> move(me);
	me -> set_temp("renwoxing/bijian", 1);
	say("任我行说道：“这位" + RANK_D->query_respect(me)+"不错，我就送你一块黑木令吧。”\n");
	return 1;
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂长老入教去！\n");
		return;
	}
	if (ob->query("betrayer"))
	{
		command("say 我是不收叛徒的。");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa",1) < 150)
	{
		command("say 我是不轻易收徒的。");
		command("say 在我教的内功上，" + RANK_D->query_respect(ob) +
			"是否还应该多下点功夫？");
		return;
	}
	if (ob->query_temp("renwoxing/bijian"))
	{
		ob->delete_temp("renwoxing/bijian");
		if ( ob->query("kar") == this_object()->query("kar"))
		{
			command("say 好吧，既然你我如此投缘，老夫就收下你了。");
                        command("xkx 老夫收得如此良徒，东方不败小儿你的报应来拉!");
			command("recruit " + ob->query("id"));
		}
		else
		{
			message_vision(
"$N拍着胸膛道：“任老先生，你一世英雄了得，何苦在这地牢之中和腐
土同朽？只须你答允收我为徒，在下言出如山，自当助你脱困。我想老
先生经过一番比剑，当年的豪情胜概，不免在心中又活了起来罢？外边
天地多么广阔，你老爷子出得黑牢，普天下的男女老幼，你要杀哪一个
便杀哪一个，无人敢与老爷子违抗，岂不痛快之极？”\n", ob);
			command("say 哼，我才不上你的当呢。");
		}
	}
	else
		command("say 好吧，我先看看你的剑法吧。");
}

