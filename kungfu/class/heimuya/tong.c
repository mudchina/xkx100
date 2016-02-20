// tong.c
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

void greeting(object me, object ob);
string ask_me();
void init();
void create()
{
	set_name("童百熊", ({ "tong baixiong","tong"}) );
	set("gender", "男性" );
	set("age", 75);
	set("long", "他白发披散, 银髯戟张, 脸上的肌肉牵动, \n"
                    "圆睁双眼, 身上的鲜血已然凝结, 神情甚是可怖。\n");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("env/wimpy", 40);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 2500);
	set("max_jing", 1500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 200);
	set("combat_exp", 350000);
	set("score", 30000);

	set_skill("force", 100);
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

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIC"风雷堂长老"NOR);
	create_family("黑木崖", 9, "弟子");

	set("chat_chance", 3);
	set("chat_msg", ({
		 "童百熊怒瞪双眼道: “我没错, 我没有叛教! 东方兄弟你不能冤枉我呀! ”\n",
	         "童百熊叹了一口气说：“我和东方兄弟出生入死, 共历患难的时候, 你们还没生下来哪!”\n"
        }) );
	setup();
        carry_object("/d/heimuya/npc/obj/zijinchui")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/heimuya/npc/obj/card1");

}

void attempt_apprentice(object ob)
{
     command("say 我是患难之身, 怎么能收徒呢。壮士还是请回吧！\n");
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
