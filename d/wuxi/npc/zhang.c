// zhang.c 泥人张 

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("泥人张", ({ "niren zhang", "zhang" }));
	set("title", "泥人铺老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long",
"泥人张的老爸叫泥人张，他爷爷也叫泥人张，反正他是祖传的泥人手艺，远近闻名。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 4000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/daafu",
		__DIR__"obj/xiaoafu",
		__DIR__"obj/niren",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
