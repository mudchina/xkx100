//Edited by fandog, 02/15/2000

inherit NPC;

void create ()
{
	set_name("周圻", ({"zhou qi","zhou"}));
	set("title","万门二弟子");
	set("long", "\n");
	set("gender", "男性");
	set("age", 26);
	set("combat_exp", 100000);
	set("str", 20);
	set("int", 25);
	set("con", 20);
	set("dex", 21);
	set("per", 20);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 80);
	set_skill("parry", 80);
	set_skill("yanfly", 80);
	set_skill("tangshi-jian", 80);
	map_skill("dodge", "yanfly");
	map_skill("parry", "tangshi-jian");
	map_skill("sword", "tangshi-jian");
	set("chat_chance", 10);
	set("chat_msg", ({
		"周圻冷冷言道：“今天是万老爷的好日子，您可别来搅局。\n",
	}) );
	setup();

	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}


