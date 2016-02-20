// yintianzheng.c
// Last Modified by winder on Oct. 30 2001

#include "ansi.h";
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("殷天正", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",
		"他是一位身材魁梧的秃老者，身穿一件白色长袍。\n"
		"他长眉胜雪，垂下眼角，鼻子钩曲，犹如鹰嘴。\n"
	);

	set("nickname", HIW "白眉鹰王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen_type", 1);
	set("per", 22);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 900000);
	set("score", 1000000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("claw", 200);
	set_skill("parry", 180);
	set_skill("blade", 180);
	set_skill("sword", 180);
	set_skill("qingfu-shenfa", 180);
	set_skill("jiuyang-shengong", 180);
	set_skill("lieyan-dao", 200);
	set_skill("liehuo-jian", 200);
	set_skill("sougu", 250);
	set_skill("literate", 100);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qingfu-shenfa");
	map_skill("claw", "sougu");
	map_skill("blade", "lieyan-dao");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	prepare_skill("claw", "sougu");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: command("perform claw.muyeyingyang") :),
	}) );
	set("party/party_name",HIG"明教"NOR);
	set("party/rank",HIW"护教法王"NOR);
	create_family("明教", 34, "弟子");
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
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
