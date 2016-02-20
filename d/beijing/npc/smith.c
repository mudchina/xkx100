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
		WEAPON_DIR"changjian",
		WEAPON_DIR"gangdao",
		WEAPON_DIR"hammer",
		"/d/beijing/obj/tudao",
		"/d/xingxiu/obj/tiegun",
	}));

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
