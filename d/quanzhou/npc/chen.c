// chen.c
// Last Modified by winder on May. 29 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("陈阿大", ({ "chen ada", "chen", "ada" }));
	set("title", "杂货铺老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 35);
	set("long", "陈阿大久居泉州城，据说他非常豪爽。\n");
	set("attitude", "friendly");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);
	set("combat_exp", 40000);
	set("vendor_goods", ({
		"/d/xingxiu/obj/fire",
		"/d/city/npc/obj/mabudai",
		"/d/city/npc/obj/muchui",
		"/d/city/npc/obj/mugun",
		"/d/city/npc/obj/beixin",
		"/d/city/npc/obj/toukui",
		"/d/city/npc/obj/cycle",
		"/d/city/npc/obj/surcoat",
		"/d/city/npc/obj/shield",
		"/d/city/npc/obj/huwan",
		"/d/city/npc/obj/zhitao",
		"/d/city/npc/obj/huyao",
		"/d/city/npc/obj/caoxie",
		"/d/city/npc/obj/pixue",
		"/d/city/npc/obj/shoutao",
		"/d/city/npc/obj/tieshou",
		"/d/city/npc/obj/jinsijia",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
