// xian.c 鲜于通
 
inherit NPC;
 
void create()
{
	set_name("鲜于通", ({ "xianyu  tong"}));
	set("nickname", "华山叛徒");
	set("long", "长的眉目清秀，俊雅潇洒，但是实际上是个阴狠歹毒的人。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 1000000+ random(500000)); 
	set("chat_msg_combat", ({				      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	set_skill("force", 100);
	set_skill("huashan-neigong", 100);
	set_skill("dodge", 150+ random(50)); 
	set_skill("feiyan-huixiang", 220+ random(50)); 
	set_skill("unarmed", 150+ random(50)); 
	set_skill("huashan-ken", 220+ random(50)); 
	set_skill("parry", 150+ random(50)); 
	set_skill("literate", 100);
	set_skill("sword",150 + random(50));
	set_skill("changge-jian",220 + random(50));
	map_skill("sword","changge-jian");
	map_skill("force", "huashan-neigong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("unarmed", "huashan-ken");
  	map_skill("parry", "huashan-ken");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 50);
}
#include "npc.h"
