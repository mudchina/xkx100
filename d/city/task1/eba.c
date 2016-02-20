// eba.c 恶霸
 
inherit NPC;
 
void create()
{
	set_name("恶霸", ({ "e  ba"}));
	set("long", 
	"一个危害一方的恶霸，强男霸女，无恶不做。\n");
	set("gender", "男性");
	set("age", random(20) + 25);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 100);
	set("combat_exp", 1000000 + random(300000)); 
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		    
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	 
	set_skill("force", 140);
	set_skill("canhe-finger", 220);
	set_skill("finger", 150);
	set_skill("shenyuan-gong", 150);
	set_skill("yanling-shenfa", 220);
	set_skill("dodge", 150 + random(20));
	set_skill("strike", 150 + random(50));
	set_skill("sword", 150 + random(50));
	set_skill("parry", 150 + random(50));
	set_skill("sword",150 + random(50));
	set_skill("changge-jian",220 + random(50));
	map_skill("sword","changge-jian");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("finger", "canhe-finger");
  	map_skill("parry", "canhe-finger");
 
	prepare_skill("finger", "canhe-finger");
  	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
