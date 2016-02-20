// gaiyiming.c ¸ÇÒ»Ãù
inherit NPC;
 
void create()
{
	set_name("¸ÇÒ»Ãù", ({ "gai  yiming", "gai" }));
	set("nickname", "°Ë²½¸Ïó¸¡¢Èü×¨Öî¡¢Ì¤Ñ©ÎÞºÛ¡¢¶À½ÅË®ÉÏ·É¡¢Ë«´Ì¸ÇÆßÊ¡");
	set("long", 
	"Ò»ÕÅÀ¯»ÆµÄÁ³£¬¶ÌÐ¡¾«º·£¬ÏÂ°Í¼âÏ÷£¬ÊÖÖÐÄÃÖøÒ»¶Ô¶ëÃ¼¸Ö´Ì¡£\n");
	set("gender", "ÄÐÐÔ");
	set("age", 25);
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
	set("combat_exp", 200000 + random(40000)); 
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		    
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	 
	set_skill("force", 60);
	set_skill("hunyuan-yiqi",100);
	set_skill("dodge", 100 + random(50));
	set_skill("dagger", 100 + random(50));
	set_skill("shigu-bifa", 150 + random(50));
	set_skill("parry", 100 + random(50));
	set_skill("literate", 20);
	set_skill("yunlong-shenfa",150 + random(50));
	map_skill("force","hunyuan-yiqi");
	map_skill("dodge","yunlong-shenfa");
	map_skill("dagger","shigu-bifa");
	map_skill("parry","shigu-bifa");
     
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/meizhuang/npc/obj/panguan-bi")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
