// hezudao.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
	set_name("何足道", ({ "he zudao", "he" }));
	set("title", "昆仑派开山祖师");
	set("nickname", "昆仑三圣");
	set("class", "taoist");
	set("long",
		"他就是昆仑派开山祖师，号称琴剑棋三绝的“昆仑三圣”。\n"
		"长脸深目，瘦骨棱棱，约莫三十岁左右年纪。\n");
	set("gender", "男性");
	set("age", 35);
	set("per", 20);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 27);
	set("int", 40);
	set("con", 40);
	set("dex", 28);

	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("eff_jingli", 2000);
	set("jingli", 2000);
	set("combat_exp", 3000000);
	set("score", 400000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		 (: perform_action, "strike.diezhang" :),
		 (: perform_action, "sword.2wu"       :),
		 (: perform_action, "sword.2wu"       :),
	}));

	set_skill("goplaying", 200);
	set_skill("luteplaying", 200);
	set_skill("literate", 180);
	set_skill("leg", 200);
	set_skill("chuanyun-leg", 300);
        set_skill("cuff", 200);
	set_skill("zhentian-cuff", 300);
	set_skill("force", 200);
	set_skill("xuantian-wuji", 200);
	set_skill("dodge", 200);
	set_skill("kunlun-shenfa", 300);
	set_skill("strike", 200);
	set_skill("kunlun-strike", 300);
	set_skill("parry", 200);
	set_skill("sword", 210);
	set_skill("liangyi-sword", 200);
	set_skill("xunlei-sword", 300);
	set_skill("throwing", 180);
	set_skill("mantian-huayu", 250);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("cuff", "zhentian-cuff");
	map_skill("leg", "chuanyun-leg");
	map_skill("strike", "kunlun-strike");
	map_skill("parry", "kunlun-strike");
	map_skill("sword", "liangyi-sword");
	map_skill("throwing", "mantian-huayu");
	prepare_skill("strike", "kunlun-strike");

	create_family("昆仑派", 1, "开山祖师");
	setup();
	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/jiaowei-qin");
		if (ob->violate_unique())
		{destruct(ob);ob=new(WEAPON_DIR"changjian");}
	  ob->move(this_object());
	  ob->wield();
	}
	carry_object("/d/kunlun/obj/pao2")->wear();
}

void attempt_apprentice(object ob)
{
	mapping skill;
	string *skl;
	int i;

	if(ob->query_int() < 32 )
	{
		command("say 弹琴下棋需要灵性极高的人才可以领悟其真谛，不致与武功背道而驰。");
		command("say "+RANK_D->query_respect(ob)+"还是先回去多读点书吧。");
		return;
	}
	if ((int)ob->query_skill("xuantian-wuji", 1) < 85)
	{
		command("say 琴棋书画虽为小技，但也需内力融入其中。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该先在玄天无极功上多下点功夫？");
		return;
	}

	if ((int)ob->query("max_neili", 1) < 500)
	{
		command("say 内力不够，一心二用则极容易走火入魔。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该先好好修炼内力？");
		return;
	}

       	skill = ob->query_skills();
	skl = keys(skill);
	i = sizeof(skl);
	while (i--)
	{
                if (skill[skl[i]] < 80)
		{
			command("say " + RANK_D->query_respect(ob) + 
			"是否在" + CHINESE_D->chinese(skl[i]) + 
			"上多下些功夫？");
			return;
		}
	}
	        
	command("recruit "+ob->query("id"));

  if (ob->is_apprentice_of(this_object()))
  if (!ob->query("appren_hezudao"))
	{
		ob->set("appren_hezudao", 1);
//	ob->add("int", 1);
  	command("say 看来你也是性情中人，我就教你一些琴剑棋的知识吧。");
	  ob->set_skill("luteplaying", ob->query_skill("xuantian-wuji", 1));
	  ob->set_skill("goplaying", ob->query_skill("xuantian-wuji", 1));
//	ob->set_skill("literate", 10 + ob->query_skill("literate", 1));
  }
}
