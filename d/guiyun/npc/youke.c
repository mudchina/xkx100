// Npc: /d/guiyun/npc/youke.c 游客
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("游客", ({ "you ke", "you", "ke" }));
	set("gender", "男性");
	set("age", 28);
	set("long", "他是一个来此游玩的人，似乎已经陶醉于山水之中。\n");
	
	set("combat_exp", 3500);
	set("shen_type", 0);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 25);
	set_skill("dodge", 25);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set("inquiry",([
		"name" : "我只是一个小角色，哪有姓名可言？",
	]));

	set("chat_chance",10);
	set("chat_msg",({
		"游客摇头晃脑地吟道：醉翁之意不在酒，在乎山水之间也。\n",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
