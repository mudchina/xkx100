// GaoShanWang.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();

void create()
{
	set_name("高山王", ({ "gao shanwang", "gao", "shanwang", }));
	set("long",
        "他是一位身宽体胖的老者，身穿一件白布长袍。\n"
        "他正笑嘻嘻地看着你，好象对你颇有好感。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");

    	set("age", 51);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("finger", 68);
	set_skill("nianhua-zhi", 68);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("damo-jian", 80);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");
	prepare_skill("finger", "nianhua-zhi");
	set("inqiry", ([
		"明教" :    (: ask_me :),
	]));

	set("party/party_name",HIG"明教"NOR);
	set("party/rank",HIW"白虎坛" NOR "坛主");
	create_family("明教", 35, "弟子");

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
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
	return "你想加入我明教(join mingjiao)吗？";
}

#include "tanzhu.h"
