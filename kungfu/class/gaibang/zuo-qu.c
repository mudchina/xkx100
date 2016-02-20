// zuo-qu.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("左全", ({"zuo quan", "zuo", "quan"}));
	set("gender", "男性");
	set("age", 35);
	set("long", 
		"这是位豪爽大方的丐帮七袋弟子，看来是个北地豪杰。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 7);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 26);

	set("max_qi", 360);
	set("max_jing", 300);
	set("neili", 710);
	set("max_neili", 710);
	set("jiali", 36);
	
	set("combat_exp", 68000);
	
	set_skill("force", 73); 
	set_skill("huntian-qigong", 70); 
	set_skill("hand", 70); 
	set_skill("suohou-hand", 73); 
	set_skill("blade", 70); 
	set_skill("liuhe-blade", 73); 
	set_skill("dodge", 70); 
	set_skill("xiaoyaoyou", 71); 
	set_skill("parry", 70); 
	set_skill("begging", 50); 
	set_skill("checking", 50);
	set_skill("strike",70); 
	
	set_skill("lianhua-zhang",70);
	set_skill("miyun-buyu",70);
	map_skill("strike","miyun-buyu");
	prepare_skill("strike", "miyun-buyu");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "liuhe-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", GRN"七袋弟子"NOR);
	set("party/level", 7);
	create_family("丐帮", 19, "弟子");
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
