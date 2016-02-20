// yulingzi.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("玉灵子", ({ "yuling zi","yuling", "zi" }));
	set("long",
		"她昆仑派第五代弟子，容颜俏丽，身材丰满，举手投足间带着点挑逗之意。\n");
	set("gender", "女");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("per", 26);
	set("str", 30);
	set("int", 23);
	set("con", 25);
	set("dex", 28);

	set("max_qi", 850);
	set("max_qi", 850);
	set("max_jing", 600);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 30);
	set("combat_exp", 380000);
	set("score", 4000);

	set_skill("force", 95);
	set_skill("xuantian-wuji", 105);
	set_skill("dodge", 95);
	set_skill("taxue-wuhen", 125);
	set_skill("parry", 100);
	set_skill("sword", 101);
	set_skill("xunlei-sword", 155);
	set_skill("leg", 90);
	set_skill("chuanyun-leg", 120);
	set_skill("throwing", 80);
	set_skill("mantian-huayu", 95);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("sword", "xunlei-jian");
	map_skill("leg", "chuanyun-leg");
	map_skill("sword", "xunlei-jian");
	prepare_skill("leg", "chuanyun-leg");

	create_family("昆仑派", 5, "弟子");
	set("env/wimpy", 60);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender")=="男性")
	{
		command("fear");
		command("say "+RANK_D->query_respect(ob)+
			"，师母不准我收男弟子，你去找我师兄去吧。");
		return;
	}

	if(ob->query_skill("xuantian-wuji",1)<60)
	{
		command("hmm");
		command("say "+RANK_D->query_respect(ob)+
			"你的玄天无极功太差，我可不想收你。");
		return;
	}

	if(ob->query("appren_hezudao", 1) == 1)
	{
		command("say 前辈怎敢开这等玩笑，真是折杀做晚辈的了。");
		return;
	}
	command("say 既然"+RANK_D->query_respect(ob)+
		"这么努力，我就收下你吧。");
	command("recruit " + ob->query("id"));
}

