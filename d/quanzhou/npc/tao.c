// tao.c
// Last Modified by winder on May. 29 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("陶老人", ({ "tao laoran", "tao", "laoren" }));
	set("gender", "男性");
	set("title", "陶然茶居老板");
	set("age", 53);
	set("long","陶老人是出名的老好人，他卖的茶又香又好，价钱公道，
所以城里的人都喜欢到他那买茶。\n");
	set("combat_exp", 200);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		TEA_DIR+"chabei",
		TEA_DIR+"guanyinchabei",
		TEA_DIR+"longjingchabei",
		TEA_DIR+"molihuachabei",
		TEA_DIR+"xiangpianchabei",
	}));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

