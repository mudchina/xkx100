// ma.c 马永康

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("马永康", ({ "ma yongkang", "ma" }));
	set("title", "杂货铺老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long",
		"马老板是土生土长的无锡人，做了几十年的小买卖。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/obj/mabudai",
		"/d/city/obj/beixin",
		"/d/city/obj/toukui",
		"/d/city/obj/cycle",
		"/d/city/obj/surcoat",
		"/d/city/obj/shield",
		"/d/city/obj/huwan",
		"/d/city/obj/zhitao",
		"/d/city/obj/huyao",
		"/d/city/obj/caoxie",
		"/d/city/obj/pixue",
		"/d/city/obj/shoutao",
		"/d/city/obj/tieshou",
		"/d/xingxiu/obj/fire",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
