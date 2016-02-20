// quan.c 全二风
 
inherit NPC;
 
void create()
{
	set_name("全二风", ({ "quan  erfeng"}));
//	set("nickname", "");
	set("long","昆仑派的叛徒，曾一度投靠朝廷，有着一张黑漆漆的脸，面目可憎。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 100);
	set("combat_exp", 1000000 + random(120000)); 
	set("chat_msg_combat", ({				      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 
	set_skill("force", 100);
	set_skill("xuantian-wuji", 100);
	set_skill("dodge", 150 + random(50));
	set_skill("kunlun-shenfa", 220 + random(50));
	set_skill("strike", 150 + random(50));
	set_skill("sword", 150 + random(50));
	set_skill("parry", 150 + random(50));
	set_skill("kunlun-strike", 220 + random(50));
	set_skill("literate", 80);
	set_skill("changge-jian",220 + random(50));
	map_skill("sword","changge-jian");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shnfa");
	map_skill("strike", "kunlun-strike");
  	map_skill("parry", "kunlun-strike");
  	prepare_skill("strike", "kunlun-strike");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 50);
}
#include "npc.h"
