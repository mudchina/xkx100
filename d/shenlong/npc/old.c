// old.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("老者", ({"old man","old","man"}));
	set("long", "这是一个神龙教老者，太阳穴高耸，两眼炯炯有神，显然武功甚高。\n然而神色郁郁，对一帮年轻男女颇为有礼，似乎害怕什么，样子十分可怜。\n");
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 30+random(50));
	set("shen_type", -1);
	set("str", 35+random(10));
	set("dex", 35+random(10));
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiaji", 25+random(25));
	set("combat_exp", 100000+random(100000));

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set("party/party_name", HIY"神龙教"NOR);
	set("party/rank", YEL"黄龙门"NOR"长老");
	set("party/level", 2);
	create_family("神龙教",2,"弟子");

	setup();
	carry_object(VEGETABLE_DIR"xionghuang");
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
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
		unconcious();
	}
	return;
}
