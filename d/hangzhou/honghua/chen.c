// chen.c 陈家洛

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("陈家洛", ({ "chen jialuo", "chen","jialuo" }));
	set("title", HIR "红花会"HIG"总舵主" NOR);
	set("long", 
"他一副模样直是个富贵人家的纨裤子弟，丰姿如玉，目朗似星，轻
袍缓带，手中摇着一柄折扇，神采飞扬，气度闲雅，吐属斯文。服
饰俨然是个贵介公子。\n");
	set("nickname", HIY"玉面神龙"NOR);
	set("gender", "男性");
	set("class", "scholar");
	set("age", 22);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("yunlong-xinfa", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("wuhu-duanmendao", 150);
	set_skill("yunlong-jian", 200);
	set_skill("yunlong-shenfa", 150);
	set_skill("yunlong-bian", 150);
	set_skill("yunlong-shou", 150);
	set_skill("yunlong-zhua", 150);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 60);

 	setup();
	carry_object(CLOTH_DIR"jinduan")->wear();
	carry_object("/d/beijing/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

