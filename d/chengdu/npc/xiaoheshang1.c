// Room: /d/chengdu/npc/xiaoheshang1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("小和尚", ({ "xiao heshang", "xiao", "heshang" }));
	set("long", "这是位年轻的和尚，看他虔诚的样子，长大后肯定是位得道高僧。\n"); 
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 14);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 1000);
	set("score", 50);

	set_skill("force", 8);
	set_skill("dodge", 8);
	set_skill("unarmed", 8);
	set_skill("parry", 8);

	setup();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
	carry_object(CLOTH_DIR"seng-shoe")->wear();
}

