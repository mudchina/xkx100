// bailong shi 白龙使
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit NPC;

string ask_ob(string);
void apply_gift(object, int);

void create()
{
	set_name("钟志灵", ({ "zhong zhiling","bailong shi", "shi","zhong" }));
	set("long", "魁梧大汉，一看就知是关东人。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 32);
	set("int", 26);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 60);
	set("combat_exp", 150000);
	set("score", 50000);
	set("shen", -20000);

	set_skill("force", 100);
	set_skill("dulong-dafa", 100);
	set_skill("dodge", 80);
	set_skill("yixingbu", 80);
	set_skill("strike", 100);
	set_skill("huagu-mianzhang", 80);
	set_skill("parry", 90);
	set_skill("hook", 150);
	set_skill("ruyi-hook", 100);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
	map_skill("hook", "ruyi-hook");

	prepare_skill("strike", "huagu-mianzhang");
	set("inquiry", ([
		"洪安通" : "这三个字是你说的吗？",
		"洪教主" : "洪教主仙福永享，寿与天齐，洪教主神目如电，烛照四方。",
		"苏荃"   : "没规没矩的。",
		"神龙岛" : "神龙岛在汝州的东北方向，从塘沽口出海便到。",
		"神龙教" : "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教"   : "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"教主"   : "教主脾气不好，要讨他欢心才好。\n",
		"口号"   : "万年不老！永享仙福！寿与天齐！文武仁圣！\n",
	]));
	set("party/party_name", HIY"神龙教"NOR);
	set("party/rank", HIW"白龙门"NOR"掌门使");
	set("party/level", 2);
	create_family("神龙教", 2, "弟子");

	setup();
	carry_object(WEAPON_DIR"hook")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();	
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_join","join");
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
		if (obj = present("usedgao", ob))          
		{
			set("combat_exp",100000);
			set("qi",100);
			set("jing",100);
		}
	}
	return;
}

void attempt_apprentice(object ob)
{
	command("say 你走开！别烦我！");
	return;
}
#include "/kungfu/class/shenlong/shenlong.h"; 
