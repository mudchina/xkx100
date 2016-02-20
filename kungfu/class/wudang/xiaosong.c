// xiaosong.c 宋青书

inherit NPC;

void create()
{
	set_name("宋青书", ({ "song qingshu", "song" }));
	set("long","他就是宋远桥的儿子宋青书。\n他今年二十岁，乃是武当第三代中出类拔萃的人物。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 0);
	set("str", 25);
	set("int", 28);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 60);
	set_skill("taiji-shengong", 60);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 100);
	set_skill("unarmed", 70);
	set_skill("taiji-quan", 100);
	set_skill("parry", 70);
	set_skill("sword", 70);
	set_skill("taiji-jian", 100);
	set_skill("taoism", 30);
	set_skill("wudang-jian", 50);
	set_skill("wudang-quan", 50);
//	set_skill("literate", 40);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("env/wimpy", 60);
        set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("武当派", 3, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}
