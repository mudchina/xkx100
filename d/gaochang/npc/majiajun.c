// majiajun.c 马家骏

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("马家骏", ({ "ma jiajun", "ma", "jiajun"}));
	set("gender", "男性");
	set("age", 35);
	set("long", 
"他一张脸胡子剃得精光，面目颇为英俊，在时明时暗的
火把光芒下，看来一片惨白，全无血色。他就是暗算师
父瓦耳拉齐后避仇哈萨克部，装扮成计爷爷的马家俊。\n");
	set("combat_exp", 50000);
	set("shen_type", 1);

	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 10);

	set_skill("force", 40);
	set_skill("sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set("inquiry", ([
		"李文秀" : "你问的是阿秀吧。\n",
	]) );

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

