//Edited by fandog, 02/15/2000

inherit NPC;

void create ()
{
	set_name("鲁坤", ({"lu kun","lu"}));
	set("title","万门大弟子");
	set("long", "\n");
	set("gender", "男性");
	set("age", 26);
	set("combat_exp", 100000);
	set("str", 20);
	set("int", 25);
	set("con", 20);
	set("dex", 21);
	set("per", 20);
	set("kar", 20);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 80);
	set_skill("parry", 80);
	set_skill("yanfly", 80);
	set_skill("tangshi-jian", 80);
	map_skill("dodge", "yanfly");
	map_skill("parry", "tangshi-jian");
	map_skill("sword", "tangshi-jian");
	setup();

	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/d/city/obj/changjian")->wield();
}


