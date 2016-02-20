// Room: /d/huijiang/npc/dizi.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;

void create()
{
	set_name("红花会弟子", ({ "di zi", "dizi" }));
	set("long", "一名普普通通的红花会弟子\n他好像二十岁了！\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 21);
	set("int", 22);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 280);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("combat_exp", 20000);
	set_skill("force", 45);
	set_skill("dodge", 45);
	set_skill("unarmed", 40);
	set_skill("parry",50);
	set_skill("sword",50);

	create_family("红花会",3, "弟子");

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}
