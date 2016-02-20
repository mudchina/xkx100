// qianlaob.c
#include <ansi.h>

inherit NPC;
inherit F_BANKER;
int ask_weiwang();

void create()
{
	set_name("钱老本", ({"qian laoben", "qian", "laoben"}));
	set("title", HIR "天地会"HIG"青木堂"NOR"会众");
	set("gender", "男性");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 800); 
	set("max_qi", 800);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 20);
	set("shen", 0);

	set("no_get", 1);
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
		"钱老本说道：我叫钱老本，就是因为做生意连老本也赔了。\n",
		"钱老本笑着说道：在本店存钱利息至少百分之一，客官您只管存吧。\n",
		"钱老本说：只有对本派弟子我才这么客气，对别的人啊，哼哼......\n",
		"钱老本突然说道: 江湖威望很重要，威望值高大有好处啊。\n",
		"钱老本突然说：五人分开一首诗，身上洪英无人知。\n",
	}));
	set("inquiry", ([
		"利息" : "想要利息先入会！\n",
		"陈近南" : "想见总舵主可没那么容易。\n",
		"天地会" : "只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"加入" : "只要入了我天地会，可以向会中各位好手学武艺。\n",
		"入会" : "只要入了我天地会，可以向会中各位好手学武艺。\n",
		"威望" : (: ask_weiwang :),
		"江湖威望" : (: ask_weiwang :),
	]) );

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 5);
}

void init()
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	delete_temp("busy");
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say( "钱老本说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
	say("钱老本又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
	return 1;
}
