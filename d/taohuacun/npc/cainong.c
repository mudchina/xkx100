// cainong.c 
inherit NPC;
inherit F_DEALER;

void  create()
{
	set_name("菜农", ({ "cai nong" }));
	set("gender", "男性");
	set("age", 25);
	set("long", "一位面孔黝黑的乡下菜农。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/bcseed",
		__DIR__"obj/qcseed",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
