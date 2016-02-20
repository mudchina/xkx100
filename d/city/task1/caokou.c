// caokou.c 草寇
 
inherit NPC;
 
void create()
{
	set_name("草寇", ({ "cao  kou"}));
//	set("nickname", "");
	set("long", 
	"一个四处流窜的草寇，坏事干了不少。\n");
	set("gender", "男性");
	set("age", random(20) + 25);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 900000 + random(300000)); 
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		
		(: perform_action, "sword.sanjue" :),	      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	 
	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 150 + random(30));
	set_skill("shaolin-shenfa", 220 + random(50));
	set_skill("strike", 150 + random(50));
	set_skill("sword", 150 + random(50));
	set_skill("kunlun-strike", 220 + random(30));
	set_skill("parry", 150 + random(50));
	set_skill("damo-jian", 220 + random(50));
	set_skill("literate", 20);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shnfa");
	map_skill("strike", "kunlun-zhang");
  	map_skill("parry", "damo-jian");
  	map_skill("sword", "damo-jian");
	prepare_skill("strike", "kunlun-zhang");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
