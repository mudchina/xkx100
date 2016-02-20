//NPC /d/wuxi/npc/polan.c
#include <ansi.h>
inherit NPC;
void greeting(object ob);
void create()
{
	set_name("破烂王", ({ "polan wang", "wang", "polan" }));
	set("gender", "男性");
	set("age", 35);
	set("long", "他一身破衣，整天在大街小巷找垃圾，富家门前拣洋落。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("qi", 200);
	set("max_qi", 200);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 10);
	set("max_neili", 10);
	set("combat_exp", 3000);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);

	set("chat_msg", ({
		(: random_move :)
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
