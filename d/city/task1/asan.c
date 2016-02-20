// asan.c 阿三
 
inherit NPC;
 
void create()
{
	set_name("阿三", ({"a  san"}));
	set("long", "金刚门的高手，一身外功出神入化，出手极其狠毒。\n");
	set("gender", "男性");
	set("age", 46);
	set("attitude", "peaceful");
	set("str", 30);
	set("int", 35);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 10);
	set("combat_exp", 3000000+ random(1000000));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	 
	set_skill("force", 200+ random(50));
	set_skill("hunyuan-yiqi", 200+ random(50));
	set_skill("dodge", 200+ random(50));
	set_skill("longzhua-gong", 300+ random(50));
	set_skill("parry", 200+ random(50));
	set_skill("shaolin-shenfa", 300+ random(50));
	set_skill("cuff", 200+ random(50));
	set_skill("claw", 200+ random(50));
	set_skill("jingang-quan", 300+ random(50));
	set_skill("literate", 200+ random(50));
	set_skill("yizhi-chan", 300+ random(50));
	set_skill("finger", 200+ random(50));
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "yizhi-chan");
	map_skill("claw", "longzhua-gong");
  	map_skill("parry", "jingang-quan");
  	map_skill("cuff", "jingang-quan");
  	prepare_skill("claw", "longzhua-gong");
        prepare_skill("finger", "yizhi-chan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);
}
#include "npc.h"
