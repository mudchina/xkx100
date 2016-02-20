// Npc: /d/lingxiao/npc/wang.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("王万仞",({"wang wanren","wang"}));
	set("gender", "男性");
	set("age", 20);
	set("long", 
	       "他是凌霄城第六代弟子王万仞，专门负责接送新入门的弟子上山。\n"
	       "他本是凌霄城中杰出弟子，只是好酒贪杯，才被罚到此守卫。\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1000);
	set("max_neili", 1000);
	set("max_jing", 1000);
	set("jing", 1000);
	set("max_qi", 1500);
	set("qi", 1500);
	set("jiali", 50);

	set("combat_exp", 200000);
	set("chat_chance", 10);
	set("chat_msg", ({
"王万仞打了个喷嚏，叹了一声：在这鬼地方，真够冷的，要是有点酒喝就暖和多了。\n", 
"王万仞说道，你要能给我点酒，我就让你进密道去，山腰小店就有卖的。\n", 
	}) );
	set("inquiry", ([
		"暗道"   : "那是只有我们凌霄弟子才能走的。",
	]));
	set("shen_type", 0);
	set("score", 20000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 120);
	set_skill("sword", 120);
	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("literate", 80);

	set_skill("xueshan-sword", 120);
	set_skill("bingxue-xinfa", 120);
	set_skill("snow-strike", 120);
	set_skill("snowstep", 120);


	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 6, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 我是不收徒，你进城找我师兄们好了。");
}

int accept_object(object me, object ob)
{
	if ((string)ob->query("name")!="牛皮酒袋")
	{
		command("say 你给我这玩意干什么。");
		return 1;
	}
	else
	{
		command("say 这位"+RANK_D->query_respect(me) + "你太好了！\n多谢了，我这就送你进密道去，不过你千万不要说是我放你进去的哦。\n");
		me->move("/d/lingxiao/andao");
		return 1;
	}
}

