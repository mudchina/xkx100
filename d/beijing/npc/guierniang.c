// /beijing/npc/guierniang.c
// Last modified by winder 2003.10.10

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("归二娘", ({ "gui erniang", "gui" }));
	set("long", 
"一个年迈的老妇，头发半白，但看起来却是精神抖擞，\n"
"脾气相当的火暴。他便是神拳无敌归心树的内人——归\n"
"二娘。\n");
	set("gender", "女性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 40);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);
	
	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 20000);

	set_skill("cuff", 100);
	set_skill("force", 100);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike", 100);
	set_skill("sword", 150);
	set_skill("huashan-sword", 150);
	set_skill("zixia-shengong", 150);
	set_skill("poyu-quan", 100);
	set_skill("hunyuan-zhang", 100);
	set_skill("feiyan-huixiang",150);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-sword");
	map_skill("strike", "hunyuan-zhang");
	map_skill("sword", "huashan-sword");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");
	set("chat_chance", 2);
	set("chat_msg", ({
		"归二娘望了归钟一眼，深深的叹了口气。\n",
	}) );	

	create_family("华山派", 31, "弟子");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"sword")->wield();

}
