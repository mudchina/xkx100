// sengren.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("僧人", ({ "seng ren", "seng", "ren" }));
	set("class", "bonze");
	set("gender", "男性");
	set("age", 65);
	set("long","这是一位年老的僧人，在此看守藏经阁已几十年了，对此地一切都十分熟悉。\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/seng-cloth")->wear();
}

