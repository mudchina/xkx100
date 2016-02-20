// wenyoufang.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("温有方", ({ "wen youfang", "wen" ,"youfang"}));
	set("gender", "无性");
	set("title", HIC"御书房太监"NOR);
	set("age", 16);
	set("long", "一个文弱的小太监，和他兄弟温有道共司御书房。\n");

	set("combat_exp", 1000);
	set("shen_type", 0);
	set("per", 20);

	set_skill("unarmed", 10);
	set_skill("blade", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	add_money("silver", random(10));
	carry_object(__DIR__"obj/tjcloth")->wear();
}
	
