// laowu.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老吴", ({ "lao wu", "lao" ,"wu"}));
	set("gender", "无性");
	set("title", HIC"东六宫太监"NOR);
	set("age", 26);
	set("long", "一个半老瘦削汉子。\n");

	set("combat_exp", 3000);
	set("shen_type", 0);

	set_skill("unarmed", 10);
	set_skill("blade", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :),
	}));

	setup();
	add_money("silver", random(10));
	carry_object(__DIR__"obj/tjcloth")->wear();
}
	
