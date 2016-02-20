// ada.c 阿大

#include <ansi.h>
inherit NPC;
 
void create()
{
	set_name("阿大", ({ "a  da", "a" }));
	set("nickname", "八臂神剑");
	set("long", 
	"原丐帮四大长老之首，出身少林，剑术之精，名动江湖，据说出手极快。\n");
	set("gender", "男性");
	set("age", 66);
	set("attitude", "peaceful");
	set("str", 30);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 100);
	set("combat_exp", 3000000+ random(1000000));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
	       (: perform_action, "sword.sanjue" :),	      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	}));
	set_skill("force", 180);
	set_skill("canhe-finger", 300+ random(50));
	set_skill("dodge", 200+ random(50));
	set_skill("damo-jian", 300+ random(50));
	set_skill("parry", 200+ random(50));
	set_skill("xiaoyaoyou", 300+ random(50));
	set_skill("finger", 200+ random(50));
	set_skill("hunyuan-yiqi", 200+ random(50));
	set_skill("literate", 150);
	set_skill("sword", 200+ random(50));
	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("finger", "canhe-finger");
	map_skill("sword", "damo-jian");
  	map_skill("parry", "damo-jian");
	prepare_skill("finger", "canhe-finger");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield(); 
	add_money("gold", 1);
}
#include "npc.h"
