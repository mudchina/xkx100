// Npc: /d/guiyun/npc/yahuan.c 丫鬟
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("丫鬟", ({ "ya huan", "ya", "huan" }));
	set("gender", "女性");
	set("age", 12);
	set("long", "她是一个小丫鬟，形容尚小，身量未足。\n");
	
	set("combat_exp", 1500 + random(100));
	set("shen_type", 0);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 15);
	set_skill("dodge", 15);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 12);
	set("max_qi", 130);
	set("max_jing", 130);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 5);

	set("inquiry",([
		"name" : "我叫烟儿，从小就被卖在这里做丫鬟。",
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
