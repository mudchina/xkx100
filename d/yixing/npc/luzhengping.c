// /d/yixing/npc/luzhengping.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit F_UNIQUE;
inherit NPC;

void create()
{
	set_name("吕正平", ({ "lu zhengping", "lu"}));
	set("title", HIC "快刀门掌门人" NOR);
	set("long", "只见他一张国字方脸，腮上一部虬髯，将大半张脸都遮没了。\n");
	set("gender", "男性");
	set("age", 41);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_qi", 1000);
	set("max_jing", 200);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	set_skill("kuangfeng-blade", 50);
	set_skill("lingxu-bu",50);
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "kuangfeng-blade");
	map_skill("blade", "kuangfeng-blade");

	set_temp("apply/attack", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);
	set("chat_chance", 8);
	set("chat_msg", ({
		"吕正平说道：长乐帮的司徒大哥与俺们有过命的交情，真想去拜访他老人家。\n",
	}) );

	set("inquiry",([
		"丁不四" : "下次再遇到这老贼，定在他全身剁上十几刀。",
		"长乐帮" : "我也正要到长乐帮拜山。",
		"司徒大哥" : "司徒大哥的事就是兄弟我的事。",
		"司徒横" : "听说长乐帮的奸贼作乱饭上害死了他。",
	]));

	setup();
	carry_object(WEAPON_DIR"gangdao")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
}

