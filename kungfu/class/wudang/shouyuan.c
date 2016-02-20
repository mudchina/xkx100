// shouyuan.c 守园道长

#include "daozhang.h"
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("成高道长", ({ "chenggao daozhang", "chenggao", "daozhang", "shouyuan" }));
	set("nickname", "守园道长");
        set("long","他是凌虚的师侄，剑术算不得很精，但年轻之时，曾在西域住过十几年，\n懂得善制炸药，现今是看守榔梅园的道长。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("str", 21);
        set("int", 21);
        set("con", 21);
        set("dex", 21);

        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 30);
        set("combat_exp", 30000);
        set("score", 4000);

        set_skill("force", 50);
        set_skill("taiji-shengong", 40);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 40);
        set_skill("unarmed", 50);
        set_skill("taiji-quan", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("wudang-jian", 40);
        set_skill("wudang-quan", 40);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");
	set("inquiry", ([
		"name" : "贫道道号成高，负责看守榔梅园，不知这位"+RANK_D->query_respect(this_player()) +"有何见教？",
		"武当" : "贫道便是武当派弟子，不知这位"+ RANK_D->query_respect(this_player())+"有何见教？",
		"武当派" : "贫道便是武当派弟子，不知这位"+ RANK_D->query_respect(this_player())+"有何见教？",
		"剑法" : "本门剑法贫道尚未练到家，不敢妄加评论。",
		"太极剑" : "嗯……这个我不大清楚。",
		"太极剑法" : "嗯……这个我不大清楚。",
		"武当剑" : "武当剑？",
		"武当剑法" : "本门剑法贫道尚未练到家，不敢妄加评论。",
		"两仪剑法" : "两仪剑法的剑招一阴一阳，一刚一柔，必须二人同使。",
		"武当两仪剑" : "两仪剑法的剑招一阴一阳，一刚一柔，必须二人同使。",
		"绕指柔剑" : "这路剑法贫道没能学会。",
		"神门十三剑" : "这路剑法贫道没能学会。",
		"武当长拳" : "拳脚功夫非贫道所长。",
		"绵掌" : "拳脚功夫非贫道所长。",
		"震山掌" : "拳脚功夫非贫道所长。",
		"虎爪绝户手" : "嗯……听说敝派好像是有这一路武功，不过贫道不大清楚。",
		"张三丰" : "敝派创派祖师，近年来常年闭关不出，我也未见过几次。",
		"张真人" : "敝派创派祖师，近年来常年闭关不出，我也未见过几次。",
		"宋远桥" : "那是敝派掌门。",
		"宋大侠" : "那是敝派掌门。",
		"俞莲舟" : "那是敝派的前辈。",
		"俞二侠" : "那是敝派的前辈。",
		"俞岱岩" : "那是敝派的前辈。",
		"俞三侠" : "那是敝派的前辈。",
		"张松溪" : "那是敝派的前辈。",
		"张四侠" : "那是敝派的前辈。",
		"张翠山" : "那是敝派的前辈，可是贫道未得有缘一见。",
		"张五侠" : "那是敝派的前辈，可是贫道未得有缘一见。",
		"殷梨亭" : "那是敝派的前辈。",
		"殷六侠" : "那是敝派的前辈。",
		"莫声谷" : "那是敝派的前辈，就在这附近的南岩。",
		"莫七侠" : "那是敝派的前辈，就在这附近的南岩。",
		"宋青书" : "宋师叔？好久都未曾见过了。",
		"冲虚" : "冲虚道长是贫道的师伯，剑法上的造诣已是出神入化，在众师伯师叔中无人可及。",
		"冲虚道长" : "冲虚道长是贫道的师伯，剑法上的造诣已是出神入化，在众师伯师叔中无人可及。",
		"谷虚" : "谷虚师伯负责在山上主持武当事务。",
		"谷虚道长" : "谷虚师伯负责在山上主持武当事务。",
		"清虚" : "清虚道长是贫道的师叔，曾与贫道一同在西域住过十几年。",
		"清虚道长" : "清虚道长是贫道的师叔，曾与贫道一同在西域住过十几年。",
		"凌虚" : "凌虚师叔在遇真宫。",
		"凌虚道长" : "凌虚师叔在遇真宫。",
		"制香" : "凌虚师叔在遇真宫。",
		"制香道长" : "凌虚师叔在遇真宫。",
		"灵虚" : "灵虚师叔在山门，负责接待香客。",
		"灵虚道长" : "灵虚师叔在山门，负责接待香客。",
		"知客" : "灵虚师叔在山门，负责接待香客。",
		"知客道长" : "灵虚师叔在山门，负责接待香客。",
		"成高" : "贫道便是成高，负责看守榔梅园，不知这位"+RANK_D->query_respect(this_player()) +"有何见教？",
		"成高道长" : "贫道便是成高，负责看守榔梅园，不知这位"+RANK_D->query_respect(this_player()) +"有何见教？",
		"守园" : "这位"+ RANK_D->query_respect(this_player()) +"太客气了，看守榔梅园的事还是我一人来做吧。",
		"守园道长" : "贫道道号成高，负责看守榔梅园，不知这位"+RANK_D->query_respect(this_player()) +"有何见教？",
		"炸药" : "贫道曾在西域学过制造炸药之术。",
		"火药" : "贫道曾在西域学过制造炸药之术。",
		"制造火药" : "制造火药？"+ RANK_D->query_respect(this_player())+"是想制造炸药吧？",
		"制造炸药" : "炸药威力过於巨大，造难用险，不知这位"+RANK_D->query_respect(this_player()) +"问来做甚？",
		"机关" : "这你得去问清虚师叔。",
		"机关削器" : "这你得去问清虚师叔。",
	]));

        create_family("武当派", 4, "弟子");

        setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}

