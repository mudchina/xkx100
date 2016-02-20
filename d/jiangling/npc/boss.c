//Edited by fandog, 02/15/2000

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("掌柜", ({ "zhang gui", "boss" }));
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 35);
	set("long", "这位掌柜是土生土长的武汉人，做了几十年的小买卖。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/jiangling/obj/tongluo",
		"/d/jiangling/obj/yumaoshan",
	}));
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
