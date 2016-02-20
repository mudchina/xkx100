// Room: /d/chengdu/npc/laolanyan.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("老烂眼", ({ "lao lanyan", "lao"}));
	set("gender", "男性");
	set("age", 25);
	set("long", "他这群小烂眼的头目，看来在小烂眼心目中还有点威信。\n");
	
	set("combat_exp", 10000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver", 5);
}
