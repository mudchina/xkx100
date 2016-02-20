// li.c

inherit NPC;

void create()
{
	set_name("李拙道人", ({ "li zhuo", "zhuo", "li" }) );
	set("gender", "男性");
	set("age", 20);
	set("long",
		"这是一个十分凶恶的崆峒派道人。\n");
	set("combat_exp", 120000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("dodge", 100);

        create_family("崆峒派", 5, "弟子");
	setup();
        carry_object("/d/wudang/obj/greenrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 10);
}
