//Edited by fandog, 02/15/2000

inherit NPC;

void create ()
{
	set_name("吴坎", ({"wu kan","wu"}));
	set("title","万门六弟子");
	set("long", "\n");
	set("gender", "男性");
	set("age", 20);
	set("combat_exp", 100000);
	set("str", 20);
	set("int", 25);
	set("con", 20);
	set("dex", 21);
	set("per", 25);
  
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("yanfly", 70);
	set_skill("tangshi-jian", 70);
	map_skill("dodge", "yanfly");
	map_skill("parry", "tangshi-jian");
	map_skill("sword", "tangshi-jian");
	setup();

	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/d/city/obj/changjian")->wield();
}
