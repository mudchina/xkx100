// smith.c
// Last Modified by Winder on May. 15 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("铁匠", ({ "tiejiang", "smith" }));
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long", "铁匠正用汗流浃背地打铁。\n");

	set("combat_exp", 500);
	set("attitude", "friendly");
	set("vendor_goods",({
		"/d/baituo/obj/dadao",
		"/clone/weapon/gangzhang",
	}));
	setup();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

