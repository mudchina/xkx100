// /d/yixing/npc/fanyifei.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit F_UNIQUE;
inherit NPC;

void create()
{
	set_name("范一飞", ({ "fan yifei", "fan"}));
	set("title", HIB "鹤笔门掌门人" NOR);
	set("long", "他是一个矮瘦的老者，一张黑脸。腰里插着判官
笔，人称‘辽东鹤’。\n");
	set("gender", "男性");
	set("age", 51);
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
	set_skill("dagger", 50);
	set_skill("shigu-bifa", 50);
	set_skill("lingxu-bu",50);
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "shigu-bifa");
	map_skill("dagger", "shigu-bifa");

	set_temp("apply/attack", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);
	set("chat_chance", 3);
	set("chat_msg", ({
		"范一飞说道：长乐帮的司徒大哥与俺们有过命的交情，真想去拜访他老人家。\n",
	}) );

	set("inquiry",([
		"丁不四" : "下次再遇到这老贼，定在他各处要穴点上一点。",
		"长乐帮" : "我也正要到长乐帮拜山。",
		"司徒大哥" : "司徒大哥的事就是兄弟我的事。",
		"司徒横" : "听说长乐帮的奸贼作乱饭上害死了他。",
	]));
	setup();
	carry_object("/d/meizhuang/npc/obj/panguan-bi")->wield();
	carry_object("/clone/misc/cloth")->wear();
}


