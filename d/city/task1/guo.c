// guo.c 过三拳
 
inherit NPC;
 
void create()
{
	set_name("过三拳", ({ "guo  sanquan"}));
	set("nickname", "神拳门主");
	set("long", 
	"神拳门的门主，一身拳法小有名声。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 150);
	set("combat_exp", 1000000 + random(500000)); 
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		    
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	}));  
	set_skill("force", 150+ random(50)); 
	set_skill("hunyuan-yiqi", 150+ random(50)); 
	set_skill("dodge", 150+ random(50)); 
	set_skill("shaolin-shenfa", 220+ random(50)); 
	set_skill("unarmed", 150+ random(50)); 
	set_skill("parry", 150+ random(50)); 
	set_skill("changquan", 220+ random(50)); 
	set_skill("literate", 60);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 20);
}

#include "npc.h"
