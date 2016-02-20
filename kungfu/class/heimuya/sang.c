// sang.c
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

void greeting(object me, object ob);
void init();
string ask_me();
void create()
{
	set_name("桑三娘", ({ "sang sanniang", "sang", "sanniang"}) );
	set("gender", "女性" );
	set("age", 45);
	set("long", "身情古怪，面无丝毫微笑，面容却相当清秀。 \n"
                    );
	set("attitude", "friendly");
	set("shen_type", -1);
	set("env/wimpy", 40);

	set("per", 24);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);

	set("max_qi", 2000);
	set("max_jing", 1200);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 350000);
	set("score", 30000);
	set("jiali", 200);
	set_skill("force", 140);
	set_skill("dodge", 130);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-jian", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong"); 
	map_skill("parry", "taiji-jian");
	map_skill("blade", "taiji-jian");

	set("inquiry", ([
		"日月神教" :    (: ask_me :),
		"入教"     :    (: ask_me :),
	]));

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIM"天香堂长老"NOR);
	create_family("黑木崖", 9, "弟子");

	set("chat_chance", 3);
	setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 我只管接引入教，不收弟子。\n");
	return;
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	add_action("do_join","join");
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

string ask_me()
{
	return "你想加入我日月神教(join riyuejiao)吗？";
}

#include "riyuejiao.h"
#include "shenjiao.h"
