// xu.c
// Last Modified by winder on May. 29 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("许老板", ({ "xu laoban", "xu", "laoban", "boss" }));
	set("title", "绸缎庄老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 35);
	set("long", "鸿翔绸缎庄乃是许老板祖传的生意，到许老板已是第四代了。\n");
	set("attitude", "friendly");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);
	set("combat_exp", 40000);
	set("vendor_goods", ({
		CLOTH_DIR+"changpao",
		CLOTH_DIR+"choupao",
		CLOTH_DIR+"cloudyshoe",
		CLOTH_DIR+"gongpao",
		CLOTH_DIR+"gongqun",
		CLOTH_DIR+"huangyi",
		CLOTH_DIR+"jinpao",
		CLOTH_DIR+"longpao",
		CLOTH_DIR+"luopao",
		CLOTH_DIR+"luoyi",
		CLOTH_DIR+"magua",
		CLOTH_DIR+"mangpao",
		CLOTH_DIR+"nichang",
		CLOTH_DIR+"pink_cloth",
		CLOTH_DIR+"pinkskirt",
		CLOTH_DIR+"piyi",
		CLOTH_DIR+"qingduanao",
		CLOTH_DIR+"skirt",
		CLOTH_DIR+"surcoat",
		CLOTH_DIR+"wulingjin",
		CLOTH_DIR+"xueshan-pao",
		CLOTH_DIR+"yuanxiang",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
