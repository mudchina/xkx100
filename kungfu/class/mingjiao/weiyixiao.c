// weiyixiao.c
// Last Modified by winder on Oct. 30 2001

#include "ansi.h";
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("韦一笑", ({"wei yixiao", "wei", "yixiao",}));
	set("long", "他长得活象是一只青翼大蝙蝠。\n他的脸色灰扑扑的。\n");
	set("nickname", HIB "青翼蝠王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 48);
	set("shen_type", 1);
	set("per", 19);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3000);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);

	set("combat_exp", 800000);
	set("score", 1000000);

	set_skill("force", 150);
	set_skill("dodge", 200);
	set_skill("strike", 200);
	set_skill("sword", 150);
	set_skill("parry", 150);
	set_skill("jiuyang-shengong", 150);
	set_skill("qingfu-shenfa", 300);
	set_skill("hanbing-mianzhang", 250);
	set_skill("literate", 100);
	set_skill("liehuo-jian",150);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qingfu-shenfa");
	map_skill("strike", "hanbing-mianzhang");
	map_skill("parry", "hanbing-mianzhang");
	map_skill("sword", "liehuo-jian");
	prepare_skill("strike","hanbing-mianzhang");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: command("perform strike.xixueqingfu") :),
	}) );
	set("party/party_name",HIG"明教"NOR);
	set("party/rank",HIW"护教法王"NOR);
	create_family("明教", 34, "弟子");
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

#include "fawang.h"
