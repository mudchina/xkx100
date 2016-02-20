// jin. 金老板

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("金老板", ({ "jin laoban", "jin" }));
	set("title", "松鹤楼老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "金老板经营祖传下来的松鹤楼已有多年。\n");
	set("combat_exp", 50000);
	set("qi", 300);
	set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set("vendor_goods", ({
		"/d/city/npc/obj/hdjiudai",
		__DIR__"obj/paigu",
	}));

	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
