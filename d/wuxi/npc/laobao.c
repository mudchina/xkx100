// npc: /d/city/npc/wei.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("老鸨", ({ "lao bao", "laobao" }) );
	set("gender", "女性" );
	set("title", "群玉院老板娘");
	set("age", 42);
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);

	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("dodge", 35);

	set("combat_exp", 25000);

	set("max_qi", 300);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("attitude", "friendly");

	setup();
	carry_object("/d/city/obj/flower_shoe")->wear();
	carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	command("look " + me->query("id"));
	if (me->query("gender")=="女性")
	{
		command("say 哎呀，这年月大姑娘也逛窑子，成何体同。");
		command("sigh");
		command("say 可惜我儿子不在，不然让他伺候你。");
	}
	command("say 楼上楼下的姑娘们，客人来了！");
	return ;
}

