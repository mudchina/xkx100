// qi.c
inherit NPC;

void create()
{
	set_name("齐元凯", ({ "qi yuankai", "qi" }));
	set("long", "此人身材瘦长，却是气宇暄昂, 似乎身怀惊人艺业。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("huashan-zhangfa", 70);
	set_skill("unarmed",80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);

	map_skill("unarmed", "huashan-zhangfa");
	map_skill("parry", "huashan-zhangfa");

	set("env/wimpy", 60);
	set("inquiry", ([
		"四十二章经": "咦，你也知道康亲王府里有宝书？\n",
		"书": "咦，你也知道康亲王府里有...？\n",
		"钥匙" : "咦，你也知道取书要金钥匙？\n",
	]) );
	set("chat_chance", 1);
	set("chat_msg", ({
		"齐元凯忽然说: 今晚取了书我就走。\n",
		"齐元凯一咬牙，说道: 这仆役太贪了，事成之后一定杀了他灭口。\n",
		"齐元凯自言自语道: 不行，只怕还有机关。\n",
	}) );
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
	add_money("gold",1);
}

