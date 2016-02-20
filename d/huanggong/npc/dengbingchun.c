// dengbingchun.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("邓炳春", ({"deng bingchun", "deng", "bingchun"}));
	set("title",HIY"神龙教"HIG"青龙使"NOR"座下弟子");
	set("nickname",HIY"假宫女"NOR);
	set("long","一个三十岁左右的的秃头汉子。\n");

	set("gender", "男性");
	set("attitude", "peaceful"); 
	set("age", 36);
	set("shen_type", -1);
	set("per", 14);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_qi", 200);
	set("max_jing", 150);
	set("neili", 200);
	set("max_neili", 200);
	set("jiaji", 5+random(5));
	set("combat_exp", 80000+random(10000));

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 60);
	set_skill("shenlong-staff", 30);
	map_skill("staff","shenlong-staff");

	setup();
	carry_object(VEGETABLE_DIR"xionghuang");
	carry_object(WEAPON_DIR"staff")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver",5);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
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
