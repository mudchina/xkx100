// Room: /d/chengdu/npc/boss2.c 王老板 
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("王永康", ({ "wang yongkan", "wang" }));
	set("title", "杂货铺老板");
	set("shen_type", 1);
	set("gender", "男性");
	set("age", 45);
	set("long", "王老板是土生土长的成都人，做了几十年的小买卖。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		ARMOR_DIR"beixin",
		ARMOR_DIR"huwan",
		ARMOR_DIR"huyao",
		ARMOR_DIR"huzhi",
		ARMOR_DIR"other/neck",
		ARMOR_DIR"other/surcoat",
		ARMOR_DIR"other/shield",
		__DIR__"obj/cycle",
		__DIR__"obj/toukui",
		__DIR__"obj/caoxie",
		__DIR__"obj/pixue",
		__DIR__"obj/shoutao",
		__DIR__"obj/tieshou",
		__DIR__"obj/mabudai",
	}));
	
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
