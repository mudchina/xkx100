// xia.c
#include <ansi.h>
inherit NPC;

int ask_me();
int ask_stop();

void create()
{
	set_name("晨宜", ({ "cheng yi", "cheng" , "yi"}) );
	set("title", "无锡知府" );
	set("gender", "女性" );
	set("age", 25);
	set("per", 24);
	set("str", 20);
	set("dex", 20);
	set("long", "这个知府祖居苏杭，长得眉清目秀。你仔细一看，原来是个女的耶！\n");
	set("combat_exp", 300000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

	setup();
	carry_object("/d/city/npc/obj/mangpao")->wear();
	add_money("silver",30);
}

