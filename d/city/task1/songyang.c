// songyang.c 宋扬
 
inherit NPC;
 
void create()
{
	set_name("宋扬", ({ "song  yang"}));
	set("long", "一个行走江湖的独角大盗，一身轻功有所造脂。\n");
	set("gender", "男性");
	set("age", 35);
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
	set("combat_exp", 1000000); 
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "strike.sanhua" :),
		 (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	}));
	set_skill("force", 150);
	set_skill("yijinjing", 150);
	set_skill("dodge", 150 + random(50));
	set_skill("shaolin-shenfa", 220+ random(50));
	set_skill("strike", 150 + random(50));
	set_skill("sanhua-zhang", 220 + random(50));
	set_skill("parry", 150 + random(50));
	set_skill("sword", 150 + random(50));
	set_skill("literate", 70);
	set_skill("changge-jian",220 + random(50));
	map_skill("sword","changge-jian");
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "sanhua-zhang");
  	map_skill("parry", "sanhua-zhang");
  	prepare_skill("strike", "sanhua-zhang");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 50);
}
#include "npc.h"
