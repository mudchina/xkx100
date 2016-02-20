// liang.c 

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("梁长老", ({"liang zhanglao", "liang", "zhanglao"}));
	set("gender", "男性");
	set("age", 55);
	set("long", 
		"梁长老是丐帮出道最久，武功最高的长老，在武林中享名已久。\n"
		"丐帮武功向来较强，近来梁长老一力整顿，更是蒸蒸日上。\n");

	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("no_get", "1");
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 120);
	
	set("combat_exp", 100000);
	
	set_skill("force", 90); 
	set_skill("huntian-qigong", 95); 
	set_skill("hand", 85); 
	set_skill("suohou-hand", 90); 
	set_skill("blade", 85); 
	set_skill("liuhe-blade", 90); 
	set_skill("dodge", 93); 
	set_skill("xiaoyaoyou", 90); 
	set_skill("parry", 80); 
	set_skill("staff", 80); 
	set_skill("fengmo-staff", 80); 
	set_skill("begging", 80); 
	set_skill("checking", 90);
	set_skill("training", 80);
	set_skill("strike",85);  // 基本掌法
	set_skill("lianhua-zhang",85); // 莲花掌
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("blade", "liuhe-blade");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "liuhe-blade");
	map_skill("dodge", "xiaoyaoyou");
	
	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", RED"九袋长老"NOR);
	set("party/level", 9);
	create_family("丐帮", 18, "传功长老");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}
/*
void init()
{
	object ob;
	mapping myfam;
	
	::init();
	if (interactive(ob = this_player()) &&
		!is_fighting() &&
		file_name(environment(ob))!="/d/city/undertre") 
	{
		myfam = (mapping)ob->query("family");
		if (!myfam || myfam["family_name"] != "丐帮")
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	message_vision("\n粱长老看到$N闯进来，大喝一声：你不是丐帮弟子，给我滚出去！\n\n", ob);
	call_out("kicking", 0, ob);	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/gaibang/inhole");
	message("vision","只听“乒”地一声，" + ob->query("name") +
		"从小门里飞了出来。\n", environment(ob), ob);
}
*/
void attempt_apprentice(object ob)
{
	if ((int)ob->query("str") < 25) {
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "臂力太弱，似乎不宜学丐帮的功夫？");
		return;
	}

	command("say 好吧，希望" + RANK_D->query_respect(ob) +
	"能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
