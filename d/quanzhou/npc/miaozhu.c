// miaozhu.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("庙祝", ({ "miao zhu", "zhu", "miaozhu" }));
	set("class", "taoist");
	set("gender", "男性");
	set("age", 65);
	set("long", "这是一位年老的庙祝，在此已几十年了，对此地一切都十分熟悉。\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/dao-cloth")->wear();
}

