// maodongzhu.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("毛东珠", ({"mao dongzhu", "mao", "dongzhu"}));
	set("title",HIY"神龙教"HIR"赤龙使"NOR"座下弟子");
	set("nickname",HIY"假太后"NOR);
	set("long",
"一个三十岁左右的贵妇，她脸色极白，目光炯炯，但眉头微蹙，似
乎颇有愁色，又好象在想什么心事，你不禁寻思：“她身为皇太后，
还有什么不开心的？啊，是了，她死了老公。就算是皇太后，死了
老公，总不会开心。”\n");

	set("gender", "女性");
	set("attitude", "peaceful"); 
	set("age", 40);
	set("per", 21);
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_qi", 200);
	set("max_jing", 150);
	set("neili", 200);
	set("max_neili", 200);
	set("jiaji", 5+random(5));
	set("combat_exp", 50000+random(10000));

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 60);
	set_skill("meiren-sanzhao", 30);
	map_skill("sword","meiren-sanzhao");

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
