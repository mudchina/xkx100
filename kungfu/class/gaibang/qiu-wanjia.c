// qiu-wanjia.c
// Modified by Venus Nov.1997

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()								   
{
	set_name("裘万家", ({"qiu wanjia", "qiu", "wanjia"}));
	set("gender", "男性");
	set("age", 16);
	set("long",
		"这是位地痞似的丐帮二袋弟子，看来是个吃得看的小地痞。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 2);
	set("str", 19);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("max_qi", 130);
	set("max_jing", 130);
	set("neili", 170);
	set("max_neili", 170);
	set("jiali", 10);
	set("combat_exp", 8000);
	set_skill("force", 35);
	set_skill("huntian-qigong", 35);
	set_skill("hand", 35);
	set_skill("suohou-hand", 35);
	set_skill("dodge", 35);
	set_skill("xiaoyaoyou", 35);
	set_skill("parry", 35);
	set_skill("begging", 35);
	set_skill("checking", 35);
	set_skill("strike",35);
	set_skill("lianhua-zhang",35);
	set_skill("feilong-zaitian",35);
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("strike","feilong-zaitian");
	prepare_skill("strike", "feilong-zaitian");

	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", HIB"二袋弟子"NOR);
	set("party/level", 2);
	create_family("丐帮", 20, "弟子");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
}
void attempt_apprentice(object ob)
{
	if( ob->query("gender") != "男性") return;
	command("say 好吧，希望你能好好学习本门武功，将来为丐帮争一口气！。");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
