// /d/yixing/npc/fengliang.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit F_UNIQUE;
inherit NPC;

void create()
{
	set_name("风良", ({ "feng liang", "feng"}));
	set("title", HIG "青龙门掌门人" NOR);
	set("long", "他是个高大的中年汉子，腰里缠九节鞭。\n");
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
	set_skill("whip", 50);
	set_skill("riyue-bian", 50);
	set_skill("lingxu-bu",50);
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "riyue-bian");
	map_skill("whip", "riyue-bian");

	set_temp("apply/attack", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);
	set("chat_chance", 10);
	set("chat_msg", ({
		"风良说道：丁不四这老贼不许别人使九节鞭，便是和老子过不去！\n",
		"风良说道：长乐帮的司徒大哥与俺们有过命的交情，真想去拜访他老人家。\n",
	}) );

	set("inquiry",([
		"丁不四" : "这老贼竟然把我的九节鞭夺走了。",
		"长乐帮" : "我也正要到长乐帮拜山。",
		"司徒大哥" : "司徒大哥的事就是兄弟我的事。",
		"司徒横" : "听说长乐帮的奸贼作乱饭上害死了他。",
		"九节鞭" : "九节鞭是找不回来了，得另外弄根鞭子当武器用。",
	]));

	setup();
	carry_object(__DIR__"obj/jiujiebian")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
}

