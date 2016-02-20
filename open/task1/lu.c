// lu.c 鹿杖客

inherit NPC;
inherit F_SKILL;
#include <ansi.h>
void create()
{
	set_name("鹿杖客", ({ "lu  zhangke", "lu" }));
	set("gender", "男性");
	set("nickname", HIC"玄冥二老"NOR);
	set("age", 54);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "他一身长须垂胸，阴毒多智，性好色。\n");
	set("combat_exp", 3000000+ random(1000000));
	set("attitude", "peaceful");
	set("neili", 2000); 
	set("max_neili", 2000);
	set("max_qi",2500);
	set("max_jing",1000);
	set("jiali", 150);
	 set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 

	set_skill("strike",  200+ random(50));
	set_skill("claw",  200+ random(50));
	set_skill("force",  200+ random(50));
	set_skill("dodge",  200+ random(50));
	set_skill("staff",  200+ random(50));
	set_skill("parry",  200+ random(50));
	set_skill("chousui-zhang",  300 + random(50));
	set_skill("sanyin-wugongzhao",  300 + random(50));
	set_skill("zhaixinggong",  300 + random(50));
	set_skill("huagong-dafa",  220 + random(50));
	set_skill("tianshan-zhang",  300 + random(50));
	map_skill("dodge", "zhaixinggong");
	map_skill("force", "huagong-dafa");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object(__DIR__"obj/luzhang")->wield();
}

#include "npc.h"
