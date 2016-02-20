// yi.c
#include <ansi.h>

inherit NPC;
int ask_lvzhuweng();

void create()
{
	set_name("易师爷", ({ "yi shiye", "yi", "shiye"}));
	set("long",
"易师爷是个瘦瘦小小、五十来岁的汉子，颏下留着一部稀稀疏
疏的胡子，衣履甚是整洁。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 14);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);

	set("max_neili", 500);
	set("jiali", 50);
	set("combat_exp", 500);

	set_skill("dodge", 10);
	set_skill("unarmed", 10);

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
	set("inquiry", ([
		"绿竹翁"     : (: ask_lvzhuweng :),
		"东城绿竹翁" : (: ask_lvzhuweng :),
		"东城"       : "东城有个绿竹翁，弹得好琴，吹得好箫。\n",
	]));

	set("chat_chance", 30);
	set("chat_msg", ({
		"东城有个绿竹翁，弹得好琴，吹得好箫。\n",
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold",1);
}
int ask_lvzhuweng()
{
	object me = this_player();
	message_vision(CYN"易师爷猛地睁圆眯眯眼，对$N说道：你也想去见识他的琴箫？那我们一起去吧。\n"NOR,me);
	set_leader(me);
	return 1;
}
