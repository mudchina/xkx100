// tiejiang.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("铁匠", ({ "tiejiang", "smith" }));
	set("title", "铁匠铺老板");
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long","这位铁匠正在叮叮当当地打着铁，发现你在注视着他，就抬起头来微笑了一下。\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
		"/clone/weapon/gangdao",
		"/clone/weapon/changjian",
		"/clone/weapon/qimeigun",
		"/clone/weapon/changbian",
		"/clone/weapon/gangzhang",
		"/d/city/npc/obj/tiejia",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

