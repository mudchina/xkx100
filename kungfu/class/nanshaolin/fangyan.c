// Npc: /kungfu/class/nanshaolin/fangyan.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
#include <ansi.h>
inherit NPC;
string ask_job();

void create()
{
	set_name("方厌", ({ "fang yan", "fang", "yan"}));
	set("long", "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n");
	set("nickname", "厕头");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("no_get", 1);
	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("shaolin-cuff", 50);
	set_skill("luohan-cuff", 50);
	set_skill("hand", 50);
	set_skill("fengyun-hand", 50);
	set_skill("qianye-hand", 50);
	set_skill("strike", 50);
	set_skill("weituo-strike", 50);
	set_skill("club", 50);
	set_skill("weituo-club", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("hand", "qianye-hand");
	map_skill("strike", "weituo-strike");
	map_skill("club", "weituo-club");
	map_skill("parry", "weituo-club");
	prepare_skill("hand", "qianye-hand");
	prepare_skill("strike", "weituo-strike");

	create_family("南少林派", 21, "弟子");
	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(WEAPON_DIR+"qimeigun")->wield();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say " +RANK_D->query_rude(ob)+"，你还亲自来上厕所啊。");
	command("laugh ");
}
#include "/kungfu/class/nanshaolin/fang.h";
