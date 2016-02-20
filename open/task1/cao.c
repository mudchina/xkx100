// cao.c 曹化淳
 
inherit NPC;
 
void create()
{
	set_name("曹化淳", ({ "cao  huachun", "cao" }));
//	set("nickname", "");
	set("long", 
	"原是朝廷的宦官，后来由于贪赃枉法，被朝廷查办的时候逃跑了。\n");
	set("gender", "无性");
	set("age", 37);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 400);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 10);
	set("combat_exp", 500000 + random(40000)); 
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		     
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	 
	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 150+ random(50));

	set_skill("shaolin-shenfa", 150 + random(50));
	set_skill("strike", 110 + random(50));
	set_skill("sword", 110 + random(50));
	set_skill("parry", 110 + random(50));
	set_skill("damo-jian", 150 + random(50));
	set_skill("kunlun-strike", 150 + random(50));
	set_skill("literate", 20);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shnfa");
	map_skill("strike", "kunlun-strike");
  	map_skill("parry", "damo-jian");
  	map_skill("sword", "damo-jian");
	prepare_skill("strike", "kunlun-strike"); 
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
