// eseng.c 恶僧
 
inherit NPC;
 
void create()
{
	set_name("恶僧", ({ "e  seng", "seng" }));
	set("long", 
	"少林的叛僧，干了不少坏事，据说时常出没在烟花柳巷。\n");
	set("gender", "男性");
	set("age", 37);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 50);
	set("combat_exp", 700000 + random(40000));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			    
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	}));  
	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100+ random(50));
	set_skill("shaolin-shenfa", 150 + random(50));
	set_skill("cuff", 100 + random(50));
	set_skill("sword", 100 + random(50));
	set_skill("luohan-quan", 150 + random(50));
	set_skill("parry", 100 + random(50));
	set_skill("damo-jian", 150 + random(50));
	set_skill("literate", 20);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shnfa");
	map_skill("cuff", "luohan-quan");
  	map_skill("parry", "damo-jian");
  	map_skill("sword", "damo-jian");
	prepare_skill("cuff", "luohan-quan");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
