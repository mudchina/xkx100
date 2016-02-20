// Last Modified by Sir 2003.11.12
// guojing.c 郭靖

inherit NPC;
#include <ansi.h>
inherit __DIR__"gysjob.c";  //义士任务
inherit __DIR__"teamjob.c"; //阻截奸细任务
inherit __DIR__"scjob.c"; //守城任务

void create()
{
	set_name("郭靖", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"北侠"NOR);
	set("gender", "男性");
	set("age", 41);
	set("long", 
		"他就是人称北侠的郭靖，既是蒙古成吉思汗的金刀驸马，又是\n"
		"江南七怪、全真派马钰、「北丐」洪七公和「老顽童」周伯通\n"
		"等人的徒弟，身兼数门武功。他身着一件灰色长袍，体态魁梧，\n"
		"敦厚的面目中透出一股威严。令人不由得产生一股钦佩之情。\n");
	set("attitude", "friendly");
	set_max_encumbrance(100000000);
	set("per", 20);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	set_temp("no_kill",1);
	set("no_get",1);
	set("chat_chance", 3);
	set("chat_msg", ({
		"郭靖叹了口气道： 蒙古兵久攻襄阳不下，一定会再出诡计，蓉儿又不在身边，这....\n",
		"郭靖说道：华筝公主近来不知可好，抽空一定要回大漠去看看她。\n",
//		(: random_move :),
	}));
	set("inquiry", ([
		"周伯通" : "你见到我周大哥了？他现在可好？\n",
		"老顽童" : "周大哥一贯这样，没点正经！\n",
		"洪七公" : "师父除了吃，就是喜欢玩。到处玩，还是为了找吃的。\n",
		"黄药师" : "那是我泰山大人。他云游四海，神龙见首不见尾的。\n",
		"一灯大师" : "在下对大师好生感激。\n",
		"欧阳锋" : "这个老毒物，害死我六位师父，一待襄阳事了，决不与他干休。\n",
		"黄蓉"   : "蓉儿是我的爱妻，你问她做甚？\n",
		"蓉儿"   : "蓉儿就是蓉儿了。你问这么多干嘛？\n",
		"郭芙"   : "这个女儿，又笨又不听话。\n",
		"郭襄"   : "襄儿生于乱世，这辈子又多艰厄。但愿她能快乐一世。\n",
		"郭破虏" : "那是我的小儿子。\n",
		"杨过"   : "过儿确实有出息。\n",
		"马钰"   : "马道长于我有半师之谊。\n",
		"丘处机" : "邱道长义薄云天，是真豪杰。\n",
		"柯镇恶" : "那是我大师父。\n",
		"朱聪"   : "那是我二师父。\n",
		"韩宝驹" : "那是我三师父。\n",
		"南希仁" : "那是我四师父。\n",
		"张阿生" : "那是我五师父。\n",
		"全金发" : "那是我六师父。\n",
		"韩小莹" : "那是我七师父。\n",
		"丐帮"   : "丐帮英雄几百年了，守卫襄阳多亏了他们。\n",
		"拜师"   : "现在蒙古人围攻襄阳，我哪有心情收徒啊！\n",
		"job"    : (: ask_job :),
		"义士"   : (: ask_job :),
		"奸细"   : (: ask_jianxi :),
		"守城"   : (: ask_shoucheng :),
		"job2"   : (: ask_shoucheng :),
	]));
	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 8000);
	set("max_jing", 8000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali", 500);
	set("combat_exp", 25000000);
	set("score", 200000);
	set_skill("force", 400);		// 基本内功
	set_skill("huntian-qigong", 400);	// 混天气功
	set_skill("unarmed", 400);		// 基本拳脚
	set_skill("xianglong-zhang", 400);	// 降龙十八掌
	set_skill("dodge", 400);		// 基本躲闪
	set_skill("xiaoyaoyou", 400);		// 逍遥游
	set_skill("parry", 400);		// 基本招架
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	prepare_skill("unarmed","xianglong-zhang");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("job_over","shoucheng");
}
