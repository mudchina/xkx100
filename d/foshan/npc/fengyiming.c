// fengyiming.c

inherit NPC;

void create()
{
	set_name("凤一鸣", ({ "feng yiming", "feng", "yiming" }));
	set("gender", "男性");
	set("age", 25);
	set("long", 
"他是佛山镇上大财主凤天南之子。只见他步履轻捷，脸上英气勃勃，显是武功不弱。\n");
	set("combat_exp", 40000);

	set_skill("unarmed", 50);
	set_skill("force", 60);
	set_skill("blade", 80);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("wuhu-duanmendao", 70);

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 10);

	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 20);
	setup();
	carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

