// zhu.c 朱安国
 
inherit NPC;
 
void create()
{
	set_name("朱安国", ({ "zhu  anguo"}));
	set("title", "朝廷钦犯");
	set("long", "朝廷追捕的要犯，一直反对朝廷。\n");
	set("gender", "男性");
	set("age", 37);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 50);
	set("combat_exp", 500000 + random(40000)); 
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "sword.sanjue" :),			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 110+ random(50));

	set_skill("shaolin-shenfa", 160 + random(50));
	set_skill("strike", 110 + random(50));
	set_skill("sword", 110 + random(50));
	set_skill("parry", 110 + random(50));
	set_skill("damo-jian", 160 + random(50));
	set_skill("literate", 70);
	map_skill("sword","damo-jian");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shnfa");
  	map_skill("parry", "damo-jian");
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
