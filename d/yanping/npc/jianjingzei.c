// /d/yanping/npc/qiangren.c

inherit NPC;

void create()
{
	set_name("剪径贼", ({ "jianjing zei","zei" }) );
	set("gender", "男性");
	set("age", 30);
	set("long", "这家伙满脸横肉一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);

	set("chat_chance", 30);
	set("chat_msg", ({
		"剪径贼一声大喊: 此山是我开，此树是我栽，若要从此过，留下裤子来！\n",
	}) );

	set_skill("unarmed", 40);
	set_skill("sword", 20);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	setup();

        carry_object(WEAPON_DIR"gangdao")->wield();
        carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver", 1);
}
