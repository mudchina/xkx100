// liuyan.c
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("柳燕", ({"liu yan", "liu", "yan"}));
	set("title",HIY"神龙教"HIR"赤龙使"NOR"座下弟子");
	set("nickname",HIY"身轻如燕"NOR);
	set("long","一个三十五六岁年纪的宫女，体态极肥，脚步却甚轻盈，脸如
满月，眼小嘴大，笑嘻嘻的看着你。\n");
	set("gender", "女性");
	set("attitude", "peaceful"); 
	set("age", 35);
	set("per", 11);
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_qi", 200);
	set("max_jing", 150);
	set("neili", 200);
	set("max_neili", 200);
	set("jiaji", 5+random(5));
	set("combat_exp", 20000+random(10000));

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 60);
	set_skill("meiren-sanzhao", 30);
	map_skill("sword","shedao-qigong");

	setup();
	carry_object(VEGETABLE_DIR"xionghuang");
	carry_object(WEAPON_DIR"sword/duanjian")->wield();
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
