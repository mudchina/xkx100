// Edited by fandog, 02/15/2000

inherit NPC;

void create()
{
	set_name("药店掌柜", ({ "zhang gui", "boss"}));
	set("gender", "男性");
	set("long", "他看上去是个风雅之人，不知道医术如何。\n");
	set("age", 45);

	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);

	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
}
