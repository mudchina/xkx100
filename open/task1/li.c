// li.c 李四摧
 
inherit NPC;
 
void create()
{
	set_name("李四摧", ({ "li  sicui", "li" }));
	set("nickname", "神箭八雄");
	set("long","原是武林中的巨寇，后来为躲避官府和仇家，随便起了个假名字。\n");
	set("gender", "男性");
	set("age", 56);
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
	 set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 

	set_skill("force", 180 + random(50));
	set_skill("xuantian-wuji", 170 + random(50));
	set_skill("dodge", 180 + random(50));
	set_skill("taxue-wuhen", 270 + random(50));
	set_skill("cuff", 180 + random(50));
	set_skill("zhentian-cuff", 270 + random(50));
	set_skill("sword", 180 + random(50));
	set_skill("xunlei-sword", 270 + random(50));
	set_skill("parry", 180 + random(50));
	set_skill("literate", 90);
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("sword", "xunlei-sword");
	map_skill("parry", "xunlei-sword");
	map_skill("cuff", "zhentian-cuff");
	prepare_skill("cuff", "zhentian-cuff");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield(); 
	add_money("silver", 50);
}
#include "npc.h"
