// Npc: /d/guiyun/npc/zhuangding3.c 庄丁
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("庄丁", ({ "zhuang ding", "zhuang", "ding" }));
	set("gender", "男性");
	set("age", 34);
	set("long", "他是归云庄的庄丁。\n");
	
	set("combat_exp", 5000 + random(500));
	set("shen_type", 0);
	set("max_qi", 200);
	set("max_jing", 200);
	set("neili", 290);
	set("max_neili", 290);
	set("jiali", 9);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_temp("apply/attack", 18);
	set_temp("apply/defense", 18);

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
