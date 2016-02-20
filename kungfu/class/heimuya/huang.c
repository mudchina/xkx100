// huang.c
inherit NPC;
inherit F_UNIQUE;
#include <ansi.h>
void create()
{
	set_name("黄伯流", ({ "huang boliu","huang","boliu"}) );
	set("gender", "男性" );
	set("nickname", HIW"银髯蛟"NOR);
	set("age", 85);
	set("long", "一部白须，直垂至胸，身材魁梧之极。\n");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("env/wimpy", 40);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 350000);
	set("jiali", 100);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("changquan",70);
	set_skill("tiyunzong", 80);

	map_skill("dodge", "tiyunzong");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	set("inquiry", ([
		"日月神教" : "你想加入我日月神教，就得找四大堂长老。",
		"入教"     : "你想加入我日月神教，就得找四大堂长老。",
	]));

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIC"风雷堂香主"NOR);
	create_family("黑木崖", 10, "弟子");

	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 我不收弟子。\n");
	return;
}

string ask_me()
{
	return "你想加入我日月神教就得去找四大长老。";
}
void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

//	add_action("do_join","join");
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

#include "riyuejiao.h"
