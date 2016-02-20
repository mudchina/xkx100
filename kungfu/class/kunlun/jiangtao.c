// jiangtao.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("蒋涛", ({ "jiang tao", "jiang"}));
	set("long",
		"他穿青色长袍，背上斜插长剑，二十八九岁年纪。\n"
		"脸罩寒霜，一副要惹事生非的模样。\n");
	set("gender", "男性");
	set("age", 20);
	set("class", "taoist");
	set("attitude", "heroism");
	set("shen_type", 1);
	set("per", 16);
	set("str", 26);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 500);
	set("max_jing", 450);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 65);
	set_skill("xuantian-wuji", 60);
	set_skill("dodge", 65);
	set_skill("taxue-wuhen", 60);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("xunlei-sword", 65);
	set_skill("cuff", 55);
	set_skill("zhentian-cuff", 70);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("sword", "xunlei-sword");
	map_skill("cuff", "zhentian-cuff");
	prepare_skill("cuff", "zhentian-cuff");
	create_family("昆仑派", 5, "弟子");
	set("env/wimpy", 60);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender")=="女性")
	{
		command("fear");
		command("say "+RANK_D->query_respect(ob)+
			"，师母不准我收女弟子，你去找我师姊去吧。");
		return;
	}

	if(ob->query("appren_hezudao", 1) == 1)
	{
		command("say 师祖怎敢开如此玩笑，晚辈却是万万不敢的！");
		return;
	}

	command("say 好吧，我就收下你，教你一些皮毛功夫。");
	command("recruit " + ob->query("id"));
}

