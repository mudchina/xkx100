// Last Modified by winder on Sep. 12 2001
// yang.c 杨成协

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("杨成协", ({ "yang chengxie", "yang","chengxie" }));
	set("title", HIR"红花会"HIG"八当家"NOR);
	set("nickname", CYN "铁塔" NOR);
	set("long","他又肥又高，善使钢鞭，鞭身甚是粗重，看模样少说也有三十来斤。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 26);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1500);
	set("max_jing", 900);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 300000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("cuff", 100);
	set_skill("hand", 100);
	set_skill("honghua-shengong", 100);
	set_skill("youlong-shenfa", 150);
	set_skill("benlei-shou", 150);
	set_skill("baihua-cuoquan", 150);

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
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiebian");
}

