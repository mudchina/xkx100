// jiabu.c
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

void greeting(object me, object ob);
string ask_me();
void init();
void create()
{
	set_name("贾布", ({ "jia bu", "jia", "bu"}) );
	set("gender", "男性" );
	set("age", 45);
	set("long", "他蜡黄瘦脸，两边太阳穴高高鼓起，便如藏了一枚枚核桃似的。\n");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("env/wimpy", 40);

	set("per", 15);
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
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("blade",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-dao", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-dao");
	map_skill("blade", "taiji-dao");

	set("inquiry", ([
		"日月神教" :    (: ask_me :),
		"入教"     :    (: ask_me :),
	]));

	set("party/party_name",HIG"明教"NOR);
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIG"青龙堂长老"NOR);
	create_family("黑木崖", 9, "弟子");

	set("chat_chance", 2);
	set("chat_msg", ({
		 "贾布叹道: “攘外必先安内，堂中令牌被盗若是被教主知道，我命休矣。”\n"
        }) );
	setup();
        carry_object("/d/heimuya/npc/obj/dadao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
     command("say 我这点皮毛，不敢，不敢！\n");
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
