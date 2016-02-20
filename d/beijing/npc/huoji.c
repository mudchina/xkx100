// huoji.c
inherit NPC;

void create()
{
	set_name("客店伙计", ({ "kedian huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18+random(20));
	set("long", "他是小客店的伙计。\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("chat_chance", 3);
	set("chat_msg", ({
		"伙计说道：你...你...你可别杀我啊，我是良...良民。\n",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

