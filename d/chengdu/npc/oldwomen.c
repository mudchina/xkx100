// Room: /d/chengdu/npc/oldwomen.c 老大娘
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("老大娘", ({ "Old women", "old", "women" }) );
	set("gender", "女性" );
	set("age", 62);
	set("long",
		"她是菜场老板，生意红火，因此衣着穿戴还算体面。\n");
	set("combat_exp", 120);
	set("attitude", "friendly");
	set("rank_info/respect", "老大娘");
	set("vendor_goods", ({
		__DIR__"obj/qingcai",
		__DIR__"obj/dabaicai",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

