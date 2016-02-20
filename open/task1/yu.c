// yu.c 玉真子
 
inherit NPC;
 
void create()
{
	set_name("玉真子", ({ "yu  zhenzi", "yu" }));
	set("title", "铁剑门的叛徒");
	set("long","铁剑门的叛徒，极其好色，虽是武林败类，但是一身功夫早就出神入化。\n");
	set("gender", "男性");
	set("age", 66);
	set("attitude", "peaceful");
	set("str", 35);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	set("per",10);
	set("eff_jingli",2000);
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 150);
	set("combat_exp", 3000000+ random(1000000));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "strike.ju" :),		 			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),	
	}));
	set_skill("strike", 220 + random(50));
	set_skill("sword", 220 + random(50));
	set_skill("dodge", 220 + random(50));
	set_skill("parry", 220 + random(50));
	set_skill("xiantian-qigong", 220 + random(50));
	set_skill("haotian-zhang",320 + random(50));
	set_skill("quanzhen-jian", 320 + random(50));
	set_skill("jinyan-gong",320 + random(50));
	set_skill("literate", 220 + random(50));
	set_skill("force",220 + random(50));
	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyan-gong");
	map_skill("strike","haotian-zhang");
	map_skill("sword", "quanzhen-jian");
	prepare_skill("strike", "haotian-zhang");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
     
}
#include "npc.h"
