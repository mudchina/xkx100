// Last Modified by winder on Sep. 12 2001
// zhang.c 章进

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("章进", ({ "zhang jin", "zhang","jin" }));
	set("title", HIR"红花会"HIG"十当家"NOR);
	set("nickname", HIM"石敢当"NOR);
	set("long", 
"他是个驼子，最是直性子。他天生残疾，可是神力惊人，练
就了一身外家的硬功夫。他身有缺陷，最恼别人取笑他的驼
背，他和人说话时自称“章驼子”，那是好端端地，然而别
人若是在他面前提到个“驼”字，甚至冲着他的驼背一笑，
这人算是惹上了祸啦。笑他之人如是常人也还罢了，如会武
艺，往往就被他结结实实的打上一顿。他在红花会中最听骆
冰的话，因他脾气古怪，旁人都忌他三分，骆冰却怜他残废，
衣着饮食，时加细心照料，当他是小兄弟一般。衣服极为光
鲜。相貌却颇为丑陋。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 12);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1200);
	set("max_jing", 700);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 120000);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("hand", 70);
	set_skill("cuff", 70);
	set_skill("honghua-shengong", 70);
	set_skill("youlong-shenfa", 150);
	set_skill("baihua-cuoquan", 150);
	set_skill("benlei-shou", 150);

	map_skill("dodge", "youlong-shenfa");
	map_skill("force", "honghua-shengong");
	map_skill("hand", "benlei-shou");
	map_skill("cuff", "baihua-cuoquan");
	map_skill("parry", "baihua-cuoquan");
	prepare_skill("hand", "benlei-shou");
	prepare_skill("cuff", "baihua-cuoquan");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "cuff.cuo" :),
		(: perform_action, "hand.yunkai" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("红花会", 2, "弟子");

 	setup();
	carry_object(WEAPON_DIR"gangzhang");
	carry_object(CLOTH_DIR"jinpao")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
}


