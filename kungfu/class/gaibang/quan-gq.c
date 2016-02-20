// gaibang npc code

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("全冠清", ({"quan guanqing", "quan", "guanqing"}));
	set("gender", "男性");
	set("nickname", "十方秀才");
	set("age", 35);
	set("long","这是位沉默寡言却颇有心计的阴毒的丐帮八袋弟子。他为人足智多谋，武功高强，但身材高瘦，相貌也甚是清秀。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 8);
	set("str", 23);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

	set("max_qi", 360);
	set("max_jing", 300);
	set("neili", 710);
	set("max_neili", 710);
	set("jiali", 36);
	
	set("combat_exp", 69000);
	
	set_skill("force", 75); 
	set_skill("huntian-qigong", 72); 
	set_skill("hand", 75); 
	set_skill("suohou-hand", 75); 
	set_skill("dodge", 68); 
	set_skill("xiaoyaoyou", 70); 
	set_skill("parry", 70); 
	set_skill("staff", 75); 
	set_skill("fengmo-staff", 75); 
	set_skill("begging", 70); 
	set_skill("training", 60);
	set_skill("strike",70);
	
	set_skill("lianhua-zhang",70);
	set_skill("shenlong-baiwei",70);
	map_skill("strike","shenlong-baiwei");
	prepare_skill("strike", "shenlong-baiwei");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "fengmo-staff");
	map_skill("staff", "fengmo-staff");
	map_skill("dodge", "xiaoyaoyou");
	
	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", HIG"大智分舵"HIY"八袋舵主"NOR);
	set("party/level", 8);
	create_family("丐帮", 11, "弟子");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	if( ob->query("con") < 20 ) return;
	command("say 你拜我为师，可要做好吃苦的准备，好好做个丐帮弟子！");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
