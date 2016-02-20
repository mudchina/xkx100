// Npc: /d/lingxiao/npc/huyan.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("呼延万善",({"huyan wanshan","huyan","wanshan"}));
	set("gender", "男性");
	set("age", 20);
	set("long", "他是凌霄城第六代弟子呼延万善。\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jing", 800);
	set("max_jing", 800);
	set("qi", 1000);
	set("max_qi", 1000);

	set("combat_exp", 200000); 
	set("chat_chance", 20);
	set("chat_msg", ({
		"呼延万善拔出剑来，舞了一个半弧，很是神气。\n", 
		"呼延万善挺了挺胸，大声说：我们凌霄城的剑法，是天下第一的剑法。\n", 
	}) ); 
	set("shen_type", 0);
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
	set_skill("dodge", 120);
	set_skill("literate", 80);

	set_skill("xueshan-sword", 120);
	set_skill("bingxue-xinfa", 120);
	set_skill("snow-strike", 120);
	set_skill("snowstep", 120);

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

