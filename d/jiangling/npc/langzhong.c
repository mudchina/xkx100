//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("走方郎中", ({"lang zhong","doctor"}));
	set("long", "这是一个摇着虎撑在沿街卖药的走方郎中。\n");
	set("gender", "男性");
	set("age", 32);
	set("combat_exp", 50000);
	set("str", 19);
	set("int", 25);
	set("con", 18);
	set("dex", 25);
	set("per", 18);
	set("kar", 18);
  
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/jiangling/obj/hucheng");
}

