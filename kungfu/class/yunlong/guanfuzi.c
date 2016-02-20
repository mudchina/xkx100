// guanfuzi.c 关安基 

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int ask_weiwang();

void create()
{
	set_name("关安基", ({ "guan anji", "guan" }));
	set("nickname", "关夫子");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 35);
	set("long", "只见他长长的胡子飘在胸前，模样甚是威严。因此人称关夫子。\n");

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1200);
	set("max_jing", 1200);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 35);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("claw", 70);
	set_skill("hand", 70);
	set_skill("literate", 50);
	set_skill("yunlong-shengong", 80);
	set_skill("yunlong-shenfa", 80);
	set_skill("yunlong-shou", 80);
	set_skill("yunlong-zhua", 80);
	map_skill("hand", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "yunlong-shou");
	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");

	set_temp("apply/attack", 35);
	set_temp("apply/damage", 25);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_msg", ({
		"关安基忽然说：本堂的香主谁来当，还轮不到我说话。\n",
		"关安基忽然说：唉，我的脾气不大好，大家可要小心了。\n",
	}));
	set("inquiry", ([
		"陈近南" : "想见总舵主可不容易啊。\n",
		"天地会" : "只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"入会" : "只要入了我天地会，可以向会中各位好手学武艺。\n",
		"反清复明" : "去屠宰场和棺材店仔细瞧瞧吧！\n",
		"威望" : (: ask_weiwang :),
		"江湖威望" : (: ask_weiwang :),
	]) );
	set("party/party_name", HIR"天地会"NOR);
	set("party/rank", HIG"青木堂"NOR"会众");
	create_family("云龙门", 2, "弟子");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

int recognize_apprentice(object ob)
{
	if (ob->query("weiwang")<50)
	{
		message_vision("$N摇了摇头。\n",this_object());
		command("tell "+ob->query("id")+" 不是天地会弟子我不教。\n"); 
		return 0;
	}
	return 1;
}

void init()
{
	add_action("do_join","join");
}

void die()
{
	message_vision("\n$N大怒道：“你敢砍老子！兄弟们会替我报仇的！”说完倒地死了。\n", this_object());
	::die();
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say( "\n关安基说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息。。。。。\n");
	say("关安基又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
	return 1;
}
#include "tiandihui.h";
