// yun.c 云中鹤

inherit NPC;
inherit F_SKILL;
#include <ansi.h>
void create()
{
	set_name("云中鹤", ({ "yun  zhonghe", "yun" }));
	set("gender", "男性");
	set("nickname", HIY"穷凶极恶"NOR);
	set("age", 34);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "此人长得又高又瘦象一杆大竹竿，说话声音忽尖忽粗，十分难
听，穿着一身青衫，一副色迷迷模样。\n");
	set("combat_exp", 3000000+ random(1000000));
	set("attitude", "peaceful");
	set("neili", 2000); 
	set("max_neili", 2000);
	set("jiali", 150);
	set("max_qi",2000);
	set("max_jing",1200);
	 set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "sword.sanjue" :),		      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 

	set_skill("strike", 200+ random(50));
	set_skill("claw", 200+ random(50));
	set_skill("force", 200+ random(50));
	set_skill("dodge", 200+ random(50));
	set_skill("parry", 200+ random(50));
	set_skill("sword", 200+ random(50));
	set_skill("hunyuan-yiqi",200+random(50));
	set_skill("huhe-quan",  320 + random(50));	
	set_skill("shaolin-shenfa",  320 + random(50));
	set_skill("damo-jian", 320+ random(50));
	map_skill("sword", "damo-jian");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "hunyuan-yiqi");
	map_skill("parry", "huhe-quan");
	map_skill("cuff", "huhe-quan");
	prepare_skill("cuff", "huhe-quan");

	setup();
	carry_object("/kungfu/class/taohua/obj/bupao")->wear();
	carry_object("/clone/weapon/changjian")->wield(); 
}

#include "npc.h"
