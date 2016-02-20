// nan.c 南海鳄神

inherit NPC;
inherit F_SKILL;
#include <ansi.h>
void create()
{
	set_name("南海鳄神", ({ "nanhai  eshen", "eshen" }));
	set("gender", "男性");
	set("nickname", HIG"凶神恶煞"NOR);
	set("age", 34);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "此人的一个脑袋大得异乎寻常，一张阔嘴中露出白森森的利齿，
一对眼睛却是又圆又小。\n");
	set("combat_exp", 3000000);
	set("attitude", "peaceful");
	set("neili", 2000); 
	set("max_neili", 2000);
	set("jiali", 100);
	set("max_qi",2500);
	set("max_jing",1000);
	set("chat_msg_combat", ({				    
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 

	set_skill("strike", 175);
	set_skill("claw", 175);
	set_skill("force", 175);
	set_skill("dodge", 175);
	set_skill("parry", 175);
	set_skill("sanyin-wugongzhao", 225);
	set_skill("chousui-zhang", 225);
	set_skill("huagong-dafa", 175);
	set_skill("shaolin-shenfa", 225);
	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "huagong-dafa");
	map_skill("parry", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	setup();
	carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}

#include "npc.h"
