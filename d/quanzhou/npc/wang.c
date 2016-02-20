// wang.c
// Last Modified by winder on May. 29 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("王通治", ({ "wang tongzhi", "wang", "tongzhi" }));
	set("title", "药铺掌柜");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 35);
	set("long", "王通治号称通治，医术如何不知道，药倒是蛮齐全的。\n");
	set("attitude", "friendly");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);
	set("combat_exp", 40000);
	set("vendor_goods", ({
		VEGETABLE_DIR+"badou",
		VEGETABLE_DIR+"baiwei",
		VEGETABLE_DIR+"baizhi",
		VEGETABLE_DIR+"baotai",
		VEGETABLE_DIR+"chaihu",
		VEGETABLE_DIR+"chantui",
		VEGETABLE_DIR+"fangfeng",
		VEGETABLE_DIR+"fuling",
		VEGETABLE_DIR+"gancao",
		VEGETABLE_DIR+"gouzhizi",
		VEGETABLE_DIR+"heye",
		VEGETABLE_DIR+"hugu",
		VEGETABLE_DIR+"huoxiang",
		VEGETABLE_DIR+"jinyinhua",
		VEGETABLE_DIR+"jugeng",
		VEGETABLE_DIR+"lurong",
		VEGETABLE_DIR+"mahuang",
		VEGETABLE_DIR+"moyao",
		VEGETABLE_DIR+"niuhuang",
		VEGETABLE_DIR+"sangye",
		VEGETABLE_DIR+"sanqi",
		VEGETABLE_DIR+"shengdi",
		VEGETABLE_DIR+"shexiang",
		VEGETABLE_DIR+"taohuaban",
		VEGETABLE_DIR+"tenghuang",
		VEGETABLE_DIR+"tianqi",
		VEGETABLE_DIR+"xionghuang",
		VEGETABLE_DIR+"xuejie",
		VEGETABLE_DIR+"zanghonghua",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
