// yanji.c

inherit NPC;

int ask_wu();
void create()
{
	set_name("阎基", ({ "yan ji", "yan" }));
	set("title", "江湖医生");
	set("gender", "男性");
	set("long", "他是一个没落江湖医生。自从得了胡家刀谱几页残篇后，武功大进。\n");
	set("age", 45);

	set("int", 20);
	set("con", 20);
	set("str", 20);
	set("dex", 20);
	set("per", 10);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("shen_type", -1);

	set("combat_exp", 50000);
	set("attitude", "heroism");

	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("hujia-daofa", 60);
	map_skill("blade", "hujia-daofa");

	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

