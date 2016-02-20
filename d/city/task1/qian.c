// qian.c 钱二败
 
inherit NPC;
 
void create()
{
	set_name("钱二败", ({ "qian  erbai"}));
	set("nickname", "神箭八雄");
	set("long", 
	"原是武林中的巨寇，后来为躲避官府和仇家，随便起了个假名字。\n");
	set("gender", "男性");
	set("age", 36);
	set("attitude", "peaceful");
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("combat_exp", 1800000+ random(500000)); 
	set("chat_msg_combat", ({				 
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 180);
	set_skill("dodge", 180 + random(50));
	set_skill("xiuluo-dao", 270 + random(50));
	set_skill("blade", 180 + random(50));
	set_skill("shaolin-shenfa", 270 + random(50));
	set_skill("unarmed", 180 + random(50));
	set_skill("changquan", 270 + random(50));
	set_skill("parry", 180 + random(50));
	set_skill("literate", 80);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "changquan");
	map_skill("parry", "xiuluo-dao");
	map_skill("blade", "xiuluo-dao");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield(); 
	add_money("silver", 50);
}
#include "npc.h"
