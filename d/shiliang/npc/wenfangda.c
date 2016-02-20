// Feb. 6, 1999 by Winder
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("温方达", ({ "wen fangda", "wen" }) );
	set("gender", "男性");
        set("title", "温家老大");
	set("age", 45);
	set("long",
		"这位便是这家大宅的主人，温氏五老的大哥：温方达。\n");
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
        set("chat_msg", ({
        "温方达突然叹了口气，说道：金蛇郎君那个淫贼害得我家小姐好惨啊。\n",
        "温方达咬牙切齿地说道：我们温家五老一定要把金蛇郎君这个淫贼碎尸万段！\n"
        "温方达骄傲地说：我们温家五老的五行阵可是天下无敌的！\n",
        }));
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
