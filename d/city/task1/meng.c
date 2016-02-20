// meng.c 孟正鹏
 
inherit NPC;
 
void create()
{
	set_name("孟正鹏", ({ "meng  zhengpeng"}));
	set("nickname", "五凤刀掌门");
	set("long", 
	"五凤刀的掌门，一身刀法传说甚为了得。\n");
	set("gender", "男性");
	set("age", 52);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	set("max_qi", 1500);
	set("max_jing", 1200);
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
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 220 + random(50));
	set_skill("cuff", 150 + random(50));
	set_skill("blade", 150 + random(50));
	set_skill("jingang-quan", 220 + random(50));
	set_skill("parry", 150 + random(50));
	set_skill("kuangfeng-blade", 220 + random(50));
	set_skill("literate", 90);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shnfa");
	map_skill("cuff", "jingang-quan");
  	map_skill("parry", "kuangfeng-blade");
  	map_skill("blade", "kuangfeng-blade");
	prepare_skill("cuff", "jingang-quan");

	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
  	add_money("silver", 20);
}
#include "npc.h"
