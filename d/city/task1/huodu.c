// huodu.c 霍都

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("霍都", ({ "huo  du"}));
	set("long",@LONG 他是金轮法王座下的三弟子。深得法王的真传。 LONG);
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 2500);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 3000000+ random(1000000));
	set("score", 150000);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 

	set_skill("force", 200+ random(50));
	set_skill("longxiang", 250+ random(50));
	set_skill("dodge", 200+ random(50));
	set_skill("shenkong-xing", 300+ random(50));
	set_skill("unarmed", 200+ random(50));
	set_skill("yujiamu-quan", 300+ random(50));
	set_skill("parry", 200+ random(50));
	set_skill("sword", 200+ random(50));
	set_skill("mingwang-jian", 300+ random(50));
	map_skill("force", "longxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("unarmed", "yujiamu-quan");
	map_skill("parry", "mingwang-jian");
	map_skill("sword", "mingwang-jian");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

#include "npc.h"
