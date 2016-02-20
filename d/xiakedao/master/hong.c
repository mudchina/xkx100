// sample master.c code

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void consider();

void create()
{
	set_name("洪七公", ({"hong-qigong", "hong", "qigong"}));
	set("nickname", CYN"北丐"NOR);
	set("gender", "男性");
	set("age", 75);
	set("long", 
		"他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_msg", ({
		"洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",
		"洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",
		"洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
//		(: random_move :),
	}));
//	set("inquiry", ([
//		"青竹林" : "东北西北东西北。\n",
//		"丐帮" : "东北西北东西北。\n",
//		"拜师" : "你可以去东城门的我帮总舵拜鲁有脚。\n",
//	]));

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 300);
	set("max_jing", 300);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 300);
	
	set("combat_exp", 1000000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 150);             // 基本内功
	set_skill("huntian-qigong", 150);    // 混天气功
	set_skill("unarmed", 180);           // 基本拳脚
	set_skill("xianglong-zhang", 180);   // 降龙十八掌
	set_skill("dodge", 150);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 150);        // 逍遥游
	set_skill("parry", 150);             // 基本招架
	set_skill("staff", 150);             // 基本棍杖
	set_skill("dagou-bang", 150);        // 打狗棒法
	set_skill("begging", 100);           // 叫化绝活
	set_skill("checking", 100);          // 道听途说
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	
	create_family("丐帮", 17, "帮主");
	setup();
	
	carry_object("/kungfu/class/gaibang/obj/yuzhu_zhang");
}

