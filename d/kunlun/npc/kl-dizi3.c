// kunlun-dizi3.c (kunlun)

inherit NPC;

void create()
{
	set_name("昆仑派女弟子", ({ "dizi"}));
	set("long",
		"她看起来容貌俏丽，似乎练过一点武功。\n");
	set("gender", "女性");
	set("age", 25);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 24);

	set("max_qi", 350);
	set("max_jing", 250);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 10);
	set("combat_exp", 15000);
	set("score", 4000);

	set_skill("force", 30);
	set_skill("xuantian-wuji", 30);
	set_skill("dodge", 40);
	 set_skill("taxue-wuhen", 40);
	set_skill("parry", 30);
	set_skill("sword", 30);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");

	create_family("昆仑派", 6, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}


