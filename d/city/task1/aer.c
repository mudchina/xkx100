// ada.c 阿二
 
inherit NPC;
 
void create()
{
	set_name("阿二", ({"a  er"}));
	set("long", "金刚门的高手，一身外功出神入化，出手极其狠毒。\n");
	set("gender", "男性");
	set("age", 56);
	set("attitude", "peaceful");
	set("str", 35);
	set("int", 20);
	set("con", 35);
	set("dex", 27);
	
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 120);
	set("combat_exp", 3000000+ random(1000000));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "cuff.jingang" :),
		(: perform_action, "sword.sanjue" :),	      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	set_skill("force", 200+ random(50));
	set_skill("hunyuan-yiqi", 200+ random(50));
	set_skill("dodge", 200+ random(50));
	set_skill("shaolin-shenfa", 300+ random(50));
	set_skill("cuff", 200+ random(50));
	set_skill("jingang-quan", 300+ random(50));
	set_skill("parry", 200+ random(50));
	set_skill("sword", 200+ random(50));
	set_skill("damo-jian", 300+ random(50));
	map_skill("sword", "damo-jian");
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
  	map_skill("parry", "jingang-quan");
  	prepare_skill("cuff", "jingang-quan");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield(); 
	add_money("gold", 1);
}
#include "npc.h"
