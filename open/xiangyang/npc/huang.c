// huang.c
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黄蓉", ({"huang rong", "huang", "rong"}));
	set("gender", "女性");
	set("age", 36);
	set("long", "她是北侠郭靖的夫人，东邪黄药师的爱女，前任丐帮帮主。\n");

	set("attitude", "peaceful");
	   
	set("per", 30);
	set("str", 18);
	set("int", 30);
	set("con", 21);
	set("dex", 26);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 0);
	   
	set("combat_exp", 500000);
	set("score", 0);
	   
	set_skill("force", 120);
	set_skill("bibo-shengong", 120);
	set_skill("unarmed", 120);
	set_skill("luoying-zhang", 120);
	set_skill("dodge", 180);
	set_skill("anying-fuxiang", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("luoying-shenjian", 120);
	set_skill("qimen-wuxing", 120);
	set_skill("cookery", 200);
	   
	map_skill("force"  , "bibo-shengong");
	map_skill("unarmed", "luoying-zhang");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("sword"  , "luoying-shenjian") ;
	   
	create_family("桃花岛", 2, "弟子");
	setup();
	carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
	carry_object("/kungfu/class/taohua/obj/shudai")->wear();

}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/蓉")) return 0;
	ob->add_temp("mark/蓉", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me = this_player();
	if (!(int)who->query_temp("mark/蓉"))
		who->set_temp("mark/蓉", 0);
	if (ob->query("money_id") && ob->value() >= 1000)
	{
		message_vision("黄蓉同意指点$N一些烹饪手艺的问题。\n", who);
		who->add_temp("mark/蓉", ob->value() / 500);
		return 1;
	}
	return 0;
}

