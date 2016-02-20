// qqzhang.c 裘千丈
// Last Modified by winder on Nov. 17 2001

#include <ansi.h>

inherit NPC;
int ask_qiubai();
int ask_naogui();
void create()
{
	set_name("裘千丈", ({ "qiu qianzhang", "qiu", "qianzhang", "zhang" }));
	set("long", 
		"他是一个白须老头，身穿黄葛短衫，足穿麻鞋，右手挥着一把大蒲扇。\n"
	"他满脸的油滑无赖的表情。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 30);
	set("con", 26);
	set("dex", 25);
	set("env/wimpy", 70);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 80);
	set("combat_exp", 100000);
	set("score", 40000);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("strike", 60);
	set_skill("spear", 60);
	set_skill("parry", 60);
	set_skill("literate", 60);
	set_skill("zhusha-zhang", 90);
	set_skill("tiexue-qiang", 90);
	set_skill("guiyuan-tunafa", 60);
	set_skill("shuishangpiao", 90);

	map_skill("force", "guiyuan-tunafa");
	map_skill("spear", "tiexue-qiang");
	map_skill("strike", "zhusha-zhang");
	map_skill("parry", "zhusha-zhang");
	map_skill("dodge", "shuishangpiao");
	prepare_skill("strike", "zhusha-zhang");

	set("env/wimpy", 60);
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		YEL"裘千丈正色道：你身上已受内伤，快回去密室中休养七七四十九日，不可见风，否则小命不保！\n\n"NOR,
		YEL"裘千丈急道：你再不住手，爷爷可就要不客气了！！！\n\n"NOR,
		(: random_move :)
	}) );
	
	set("inquiry", ([
		"name" : "记得先父曾给我起过一个名，叫甚么‘千丈’。我念着不好听，也就难得用它。\n",
		"here" : "这里就是铁掌帮的总坛所在，你如没事，不要四处乱走，免招杀身之祸！！！\n",
		"上官剑南" : (: ask_qiubai :),
		"闹鬼" : (: ask_naogui :),
	]));

	set("chat_chance", 10);
	set("chat_msg", ({
		"裘千丈大大咧咧的说道：“铁掌帮上上下下的事情，没有爷爷不知道的！”\n",
		"裘千丈神秘的说道：“无名峰上有一座坟墓，听说那里经常闹鬼！”\n",
		"裘千丈神秘的说道：“一旦内功基础有成，就可以从花草树木中采气来提高了！”\n",
		"裘千丈说道：“中指峰第二指节处，有一个神秘的所在，听说是已故帮主的埋骨之处！”\n",
		(: random_move :)
	}) );
	create_family("铁掌帮", 14, "弟子");
	setup();
	carry_object(__DIR__"obj/yellowcloth")->wear();
	carry_object(WEAPON_DIR+"spear/tieqiang")->wield();
}

void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > 0)
	{
		command("hehe");
		command("say 他妈的！爷爷我最恨你这样心慈手软的小王八蛋！。");
		return;
	}
	command("haha");
	command("say 爷爷我武功盖世，你这娃娃好好跟着我学，准没错！");
	command("recruit " + me->query("id"));
}
int ask_qiubai()
{
	say( "他是铁掌帮的第十三代帮主。听说十年前遭了暗算，死在湖北，不知是真是假！\n");
	return 1;
}
int ask_naogui()
{
	say( "听一些帮众说，经常听见无名峰上的坟墓中，传出响声！嘿嘿！一定有什么蹊跷在里面！\n");
	this_player()->set_temp("marks/闹1", 1);
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "怕是活腻了，来来来，让爷爷教训教训你！！\n");
	command( "say 啊哟，糟糕，糟糕，这会儿当真不凑巧！你等一会，我肚子痛，要出恭！\n");
	return 0;
}
