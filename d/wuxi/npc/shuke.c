// shuke.c

inherit NPC;

void create()
{
	set_name("书客",({ "shuke" }) );
	set("gender", "男性" );
	set("age", 26);
	set("long", 
"这是个听书的书客，一副专注的神情，对进出的人等视而不见。\n");
	set("combat_exp", 5000);
	set("shen_type", 1);
	set("str", 20);
	set("per", 20);
	set("dex", 20);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}

