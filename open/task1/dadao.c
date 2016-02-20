// dadao.c 江洋大盗
 
inherit NPC;
 
void create()
{
	set_name("江洋大盗", ({ "jiangyang  dadao", "dadao" }));
	set("long", 
	"一个无恶不做的江洋大盗，四处打家劫舍，作恶多端。\n");
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
	set("combat_exp", 800000 + random(300000)); 
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
 
	set_skill("force", 150);
	set_skill("huagong-dafa", 150);
	set_skill("dodge", 150 + random(50));
	set_skill("zhaixinggong", 220 + random(50));
	set_skill("strike", 150 + random(50));
	set_skill("sword", 150 + random(50));
	set_skill("parry", 150 + random(50));
	set_skill("chousui-zhang", 220 + random(50));
	set_skill("claw", 150 + random(50));
	set_skill("sanyin-wugongzhao", 220 + random(50));
	set_skill("wudang-jian", 220 + random(50));
	set_skill("literate", 20);
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
  	map_skill("parry", "wudang-jian");
  	map_skill("sword", "wudang-jian");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
