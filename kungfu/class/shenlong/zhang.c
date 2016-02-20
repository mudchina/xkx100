// zhang.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("张淡月", ({ "zhang danyue", "zhang"}));
	set("long", "这是一个黑衣大汉，脸色大变，身子发颤，似乎恐惧已极。\n" );
	set("gender", "男性");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi",3000);
	set("qi",3000);
	set("max_jing",1000);
	set("jing",1000);
	set("combat_exp", 500000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("leg", 85);
	set_skill("hook", 85);
	set_skill("yixingbu", 85);
	set_skill("jueming-leg", 85);
	set_skill("dulong-dafa", 90);
	set_skill("ruyi-hook", 85);
	set_skill("parry", 70);
	set_skill("literate", 70);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("leg", "jueming-leg");
	map_skill("hook", "ruyi-hook");
	map_skill("parry", "jueming-leg");
	prepare_skill("leg", "jueming-leg");
	set("env/wimpy", 60);
	set("party/party_name", HIY"神龙教"NOR);
	set("party/rank", BLK"黑龙门"NOR"掌门使");
	set("party/level", 2);
	create_family("神龙教", 2, "弟子");

	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
	set("inquiry", ([
		"洪安通" : "这三个字是你说的吗？",
		"洪教主" : "洪教主仙福永享，寿与天齐，洪教主神目如电，烛照四方。",
		"苏荃"   : "没规没矩的。",
		"神龙岛" : "神龙岛在汝州的东北方向，从塘沽口出海便到。",
		"神龙教" : "一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"入教"   : "一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"教主"   : "教主脾气不好，要讨他欢心才好。\n",
		"口号"   : "万年不老！永享仙福！寿与天齐！文武仁圣！\n",
	]) );
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(__DIR__"obj/shenlongci")->wield();
	add_money("silver", 10);
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
