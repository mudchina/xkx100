// Npc: /d/lingxiao/npc/wang-wanyi.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC; 

void create()
{
	set_name("汪万翼",({"wang wanyi","wang"}));
	set("nickname", HIG"草上飞"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", "他是凌霄城第六代弟子耿万钟，在凌霄城中以轻功见长。\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 40);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("max_qi", 2000);
	set("qi", 2000);
	set("jiali", 50);
	set("inquiry", ([
	    "dodge"  : "我的轻功吗……？我们凌霄城，可是练轻功的好地方。\n老爷子还不知道，他的宝贝，可是一个好东西。",
	    "轻功"   : "我的轻功吗……？我们凌霄城，可是练轻功的好地方。\n老爷子还不知道，他的宝贝，可是一个好东西。",
	]) ); 
	set("combat_exp", 200000);
	set("shen_type", 1);
	set("score", 20000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 120);
	set_skill("sword", 120);
	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("dodge", 300);
	set_skill("literate", 80);

	set_skill("xueshan-sword", 120);
	set_skill("bingxue-xinfa", 120);
	set_skill("snow-strike", 120);
	set_skill("snowstep", 300);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 6, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
} 

