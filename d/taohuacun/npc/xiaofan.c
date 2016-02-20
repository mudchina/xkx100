// xiaofan.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("Ð¡··", ({ "xiao fan" }));
	set("gender", "ÄÐÐÔ");
	set("age", 25);
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/ljcha",
		__DIR__"obj/hdjiudai",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();	
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
