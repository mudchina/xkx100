// hua.c 花剑影
inherit NPC;
 
void create()
{
	set_name("花剑影", ({ "hua  jianying"}));
	set("nickname", "流星赶月");
	set("long","他有着一个好听的名字，中等身材，白净脸皮，若不是一副牙齿向外突了一寸，一个鼻头低陷了半寸，倒算是一位相貌英俊的人物，可惜功夫平平，还时常打劫一些路客。\n");
	set("gender", "男性");
	set("age", random(10) + 25);
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
	set("combat_exp", 400000 + random(40000)); 
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	
	set_skill("force", 60);
	set_skill("dodge", 100 + random(50));
	set_skill("tiezhang-zhangfa", 150 + random(50));
	set_skill("shuishangpiao",150 + random(50));
	set_skill("strike", 100 + random(50));
	set_skill("unarmed", 100 + random(50));
	set_skill("parry", 100 + random(50));
	set_skill("literate", 20);
	set_skill("sword",100 + random(50));
	set_skill("changge-jian",150 + random(50));
	map_skill("sword","changge-jian");
	map_skill("strike","tiezhang-zhangfa");
	map_skill("parry","tiezhang-zhangfa");
        map_skill("dodge","shuishangpiao");
        
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
