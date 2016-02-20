// ye.c

inherit NPC;
inherit F_SKILL;
#include <ansi.h>
void create()
{
	set_name("叶二娘", ({ "ye  erniang", "ye" }));
	set("gender", "女性");
	set("nickname", HIR"无恶不作"NOR);
	set("age", 43);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "一个中年女子，身穿淡青色长袍，左右脸颊上各有三条血痕。\n");
	set("combat_exp", 3000000+ random(1000000));
	set("attitude", "peaceful");
	set("neili", 2000); 
	set("max_neili", 2000);
	set("max_qi",2000);
	set("max_jing",1200);
	set("jiali", 100);
	 set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 

	set_skill("strike", 200+ random(50));
	set_skill("claw", 200+ random(50));
	set_skill("force", 200+ random(50));
	set_skill("blade", 200+ random(50));
	set_skill("dodge", 200+ random(50));
	set_skill("parry", 200+ random(50));
	set_skill("sanyin-wugongzhao",  300 + random(50));
	set_skill("chousui-zhang",  300 + random(50));
	set_skill("huagong-dafa",  220 + random(50));
	set_skill("kuangfeng-blade",  300 + random(50));
	set_skill("shaolin-shenfa",  300 + random(50));
	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "huagong-dafa");
	map_skill("blade", "kuangfeng-blade");
	map_skill("parry", "kuangfeng-blade");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	setup();
	carry_object("/kungfu/class/taohua/obj/bupao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

#include "npc.h"
