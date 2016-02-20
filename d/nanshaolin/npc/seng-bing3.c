// Last Modified by Winder on May. 29 2001
// Npc: /d/nanshaolin/npc/seng-bing3.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("守寺僧兵", ({ "seng bing", "seng", "bing"}));
	set("long",
		"他是一位身材高大的壮年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);

	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiaji", 50);
	set("combat_exp", 10000);
	set("score", 1);

	set_skill("force", 30);
	set_skill("zhanzhuang-gong", 30);
	set_skill("dodge", 30);
	set_skill("yiwei-dujiang", 30);
	set_skill("strike", 30);
	set_skill("boruo-strike", 30);
	set_skill("claw", 30);
	set_skill("dragon-claw", 30);
	set_skill("blade", 30);
	set_skill("cibei-blade", 30);
	set_skill("parry", 30);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("strike", "boruo-strike");
	map_skill("claw", "dragon-claw");
	map_skill("parry", "cibei-blade");
	map_skill("blade", "cibei-blade");
	prepare_skill("strike", "boruo-strike");
	prepare_skill("claw", "dragon-claw");

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "banruo-strike");
	map_skill("parry", "cibei-dao");
	map_skill("blade", "cibei-dao");

        create_family("南少林派", 22, "弟子");
	setup();

	carry_object(WEAPON_DIR+"blade/jiedao")->wield();
	carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) && !environment(ob)->query("no_fight") &&
		!ob->query("luohan_winner") && !present("yingxiong ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "南少林派" ) )
	{
		if( !ob->query_temp("warned") )
		{
			command("say 你是谁？  怎么闯到南少林寺里来了？！");
			command("say 快给我速速离开，下次看到决不轻饶！");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say 大胆狂徒，竟敢闯到南少林寺里来撒野！！\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}
