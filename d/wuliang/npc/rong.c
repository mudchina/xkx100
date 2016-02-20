// Npc: /rong.c
// Date: Oct.18 1999 by Winder

inherit NPC;
void create()
{
	set_name("容子矩", ({ "rong ziju", "rong", "ziju"}));
	set("long",
		"他是一位身材高大的中年道人。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "taoist");

	set("age", 40);
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 850);
	set("max_neili", 850);
	set("jiali", 40);
	set("combat_exp", 80000);
	set("score", 100);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	set_skill("parry", 60);
	set_skill("damo-jian", 60);
	set_skill("sword", 60);

	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	set("inquiry", ([
		"无量玉壁"  : "那是本派禁地，任何外人不得擅入。干犯禁忌，可叫你死葬身之地。",
	]));

	create_family("无量剑东宗", 4, "弟子");
	setup();

        carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

