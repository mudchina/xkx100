// shen.c
// Date: Oct.18 1999 by Winder
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("阿胜", ({ "sheng" }));
	set("title", HIY"神农帮帮众"NOR);
	set("age", 32);
	set("gender", "男性");
	set("long", "这是一个神农帮的帮众，身穿黄衣，肩悬药囊，手持一柄药锄。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("combat_exp", 30000);
	set("shen_type", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("hammer", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 60);

	setup();
	carry_object("/d/xingxiu/npc/obj/yaochu")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

