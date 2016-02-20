// Room: /d/jueqinggu/npc/puren1.c.c
// Last Modified by winder on Feb. 17 2001

inherit NPC;

void create()
{
	set_name("仆人", ({ "pu ren", "pu", "ren" }));
	set("long",
		"绝情谷公孙止的贴身仆人，身强力壮，似乎有些能耐。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "friendly");
	set("shen", -1000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);

	set("max_qi", 600);
	set("max_jing", 800);
	set("neili", 1200);
	set("max_neili", 800);
	set("jiali", 10);
	set("combat_exp", 100000);

	set_skill("force", 80);
	set_skill("xuantian-wuji", 80);
	set_skill("dodge", 80);
	set_skill("kunlun-shenfa", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("liangyi-jian", 80);
	set_skill("throwing", 80);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("sword", "liangyi-jian");
 
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

 
