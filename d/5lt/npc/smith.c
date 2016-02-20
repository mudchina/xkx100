// smith.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("Ìú½³", ({ "tiejiang", "smith" }));
	set("title", "Ìú½³ÆÌÀÏ°å");
	set("shen_type", 1);

	set("gender", "ÄÐÐÔ" );
	set("age", 33);
	set("long", "Ìú½³ÕýÓÃÌúÇ¯¼Ð×¡Ò»¿éºìÈÈµÄÌú¿é·Å½øÂ¯ÖÐ¡£\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
		"/d/5lt/npc/obj/gangkui",
		"/d/5lt/npc/obj/tiejia",
	}));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}