// Npc: /zuo.c
// Date: Oct.18 1999 by Winder

inherit NPC;
void create()
{
	set_name("左子穆", ({ "zuo zimu", "zuo", "zimu"}));
	set("long",
		"他是一位的五十多岁的老者，右手捻着长须，神情甚是得意。\n");

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "taoist");

	set("age", 52);
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 40);
	set("combat_exp", 150000);
	set("score", 100);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("changquan", 80);
	set_skill("parry", 80);
	set_skill("damo-jian", 80);
	set_skill("sword", 80);

	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	set("inquiry", ([
		"无量玉壁"  : "那是本派禁地，任何外人不得擅入。干犯禁忌，可叫你死葬身之地。",
	]));

	create_family("无量剑东宗", 4, "掌门");
	setup();

        carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

