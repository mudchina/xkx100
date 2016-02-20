// xingren.c 行人

inherit NPC;

void create()
{
	set_name("行人", ({ "xing ren", "ren" }));
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一个匆匆赶路的行人，没空理你。\n");
	set("combat_exp", 1000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver",2);
}
