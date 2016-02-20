// huoji. 屠宰场伙计

inherit NPC;

void create()
{
	set_name("屠宰场伙计", ({ "huo ji", "huo","ji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他十分强壮，看上去会几分武功。\n");
	set("combat_exp", 10000);
	set_skill("unarmed", 30);
	set_skill("blade", 60);
	set_skill("dodge", 30);
	set_skill("parry", 50);
	set("attitude", "friendly");
	setup();
        carry_object("/d/beijing/obj/tudao")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver", 5);
}

