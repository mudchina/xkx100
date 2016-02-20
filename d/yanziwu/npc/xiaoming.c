// xiaoming.c
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("小茗", ({ "xiao ming","ming" }) );
	set("gender", "女性" );
	set("title", HIG"蔓陀山庄青衣小环"NOR );
	set("age", 18);
	set("long", "这是一个蔓陀山庄的丫环。\n");
	set("shen_type", 1);
	set("combat_exp", 1000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("score", 800);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("sword", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
