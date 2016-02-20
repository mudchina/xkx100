// Npc: /d/guiyun/npc/zhuangding1.c 庄丁
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("庄丁", ({ "zhuang ding", "zhuang", "ding" }));
	set("gender", "男性");
	set("age", 32);
	set("long", "他是归云庄的庄丁。\n");
	
	set("combat_exp", 4000 + random(300));
	set("shen_type", 0);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_temp("apply/attack", 16);
	set_temp("apply/defense", 15);
	set("max_qi", 170);
	set("max_jing", 170);
	set("neili", 240);
	set("max_neili", 240);
	set("jiali", 8);

	set("inquiry",([
		"name" : "我只是一个小角色，哪有姓名可言？",
	]));
	setup();
	set("chat_chance",10);
	set("chat_msg",({
		"庄丁对着你笑了笑道：请随便逛，到我们这里来就不必拘束。\n",
	}));
	carry_object("/clone/misc/cloth")->wear();
}
