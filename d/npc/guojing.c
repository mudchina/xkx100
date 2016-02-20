// guojing.c 郭靖

#include <ansi.h>

inherit NPC;
int ask_rong();
void create()
{
	set_name("郭靖", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"北侠"NOR);
	set("gender", "男性");
	set("age", 25);
	set("long", 
		"他就是人称北侠的郭靖，既是蒙古成吉思汗的金刀驸马，又是\n"
		"江南七怪、全真派马钰道长、「北丐」洪七公和「老顽童」周\n"
		"伯通等人的徒弟，身兼数门武功。\n"
		"他身着一件灰色长袍，体态魁梧，敦厚的面目中透出一股威严\n"
		"令人不由得产生一股钦佩之情。\n");
 	set("attitude", "peaceful");
	
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("chat_chance", 1);
	set("chat_msg", ({
		"郭靖叹了口气道：“蒙古兵久攻襄阳不下，一定会再出诡计，蓉儿又不在身边，这....\n",
		"郭靖说道：“华筝公主近来不知可好，抽空一定要回大漠去看看她。\n",
//		(: random_move :),
	}));

	set("inquiry", ([
		"黄蓉" : "蓉儿是我的爱妻，你问她做甚？\n",
		"蓉儿" : (:ask_rong:),
		"丐帮" : "东北西北东西北。\n",
		"拜师" : "现在蒙古人围攻襄阳，我哪有心情收徒啊！\n",
	]));

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	
	set("combat_exp", 800000);
	set("score", 200000);
	 
	set_skill("force", 150);		// 基本内功
	set_skill("huntian-qigong", 130);	// 混天气功
	set_skill("unarmed", 220);		// 基本拳脚
	set_skill("xianglong-zhang", 200);	// 降龙十八掌
	set_skill("dodge", 100);		// 基本躲闪
	set_skill("xiaoyaoyou", 80);		// 逍遥游
	set_skill("parry", 120);		// 基本招架
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}
int ask_rong()
{
    object ob;
    ob = this_player();
    if (ob->query_int()>=30)
    {
        ob->set_temp("marks/蓉儿",1);
        command("say " + ob->query("name") + "，你帮我带个口信去桃花岛吧！\n");
    }
    else
    {
        command("say " + ob->query("name") + "，你打听这干嘛？\n");
    }
    return 1;
}
