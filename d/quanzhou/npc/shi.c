// shi.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("施琅", ({ "shi lang", "lang", "shi" }));
	set("title", "大清靖海侯");
	set("str", 30);
	set("dex", 30);
	set("gender", "男性");
	set("age", 35);
	set("attitude", "friendly");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("spear", 50);
	set("combat_exp", 200000);
	
	setup();
	carry_object("/clone/armor/jinjia")->wear();
	carry_object("/clone/weapon/spear/jinqiang")->wield();
}

