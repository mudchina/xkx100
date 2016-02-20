// laoban.c 老板 

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("老板", ({ "lao ban", "boss" }));
	set("shen_type", 1);
	set("gender", "男性");
	set("age", 45);
	set("long","老板是土生土长的岳阳，做了几十年的小买卖，最怕的就是乞丐进门了。可是身在岳阳，又不想离土远走，又有什么办法呢？。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/xingxiu/obj/fire",
		WEAPON_DIR"muchui",
		WEAPON_DIR"club",
		ARMOR_DIR"beixin",
		ARMOR_DIR"huwan",
		ARMOR_DIR"huxin",
		ARMOR_DIR"huyao",
		ARMOR_DIR"huzhi",
		ARMOR_DIR"niupi",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("老板满脸堆笑地说道：这位" + RANK_D->query_respect(ob) + "，多承惠顾，随便看看要点什么。\n");
}

