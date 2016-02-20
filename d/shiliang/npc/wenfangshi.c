// Feb. 6, 1999 by Winder
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("温方施", ({ "wen fangshi", "wen" }) );
	set("gender", "男性");
        set("title", "温家老四");
	set("age", 45);
	set("long",
		"这位便是温家老四：温方施。\n");
	set("combat_exp", 1000000);
        set("shen_type", 1);
	set("attitude", "heroism");
	set("str", 30);
	set("con", 25);
	set("int", 20);
	set("dex", 30);
	set("max_qi", 500);
	set("eff_qi", 500);
	set("qi", 500);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("shen_type", 0);
        set("chat_chance", 15);
	set("inquiry", ([
		"金蛇郎君" : "夏雪宜这个大淫贼，我一定要把他碎尸万断！" ,
		"温仪"   : "这个小丫头中了邪了，被我关了起来，我也是为她好啊。",
	]) );
	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_skill("sword", 100);
	set_skill("unarmed", 80);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}
