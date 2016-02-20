// ding.c
// Last Modified by winder on Sep. 27 2001

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("丁坚", ({"ding jian","ding",}));
	set("long", "他就是隐居江湖数年的一字电剑丁坚，现在在梅庄当管家。\n");
	set("gender", "男性");
	set("nickname", HIC"一字电剑"NOR);
	set("attitude", "friendly");

	set("age", 30);
	set("shen_type", 1);
	set("str", 17);
	set("int", 24);
	set("con", 20);
	set("dex", 22);
	set("max_qi", 3350);
	set("max_jing", 2200);
	set("neili", 1350);
	set("max_neili", 1350);
	set("jiali", 1);
	set("combat_exp", 100000);
	set("score", 100);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 120);
	set_skill("parry", 100);

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIW"教众"NOR);
	create_family("黑木崖", 10, "弟子");

	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/meizhuang/obj/yaoshi");
}

