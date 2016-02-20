// he-bj.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("何不净", ({"he bujing", "he", "bujing"}));
	set("gender", "男性");
	set("age", 30);
	set("long", 
		"这是位衣著邋塌，蓬头垢面的丐帮七袋弟子。\n");
	set("attitude", "heroism");
	set("class", "beggar");
 	set("beggarlvl", 7);
	set("str", 28);
	set("int", 18);
	set("con", 24);
	set("dex", 20);

	set("max_qi", 380);
	set("max_jing", 300);
	set("neili", 680);
	set("max_neili", 680);
	set("jiali", 34);
	
	set("combat_exp", 70000);
	
	set_skill("force", 70); 
	set_skill("huntian-qigong", 75); 
	set_skill("hand", 75); 
	set_skill("suohou-hand", 75); 
	set_skill("dodge", 65); 
	set_skill("xiaoyaoyou", 70); 
	set_skill("parry", 73); 
	set_skill("begging", 60); 
	set_skill("stealing", 70); 
	set_skill("strike",70);
	
	set_skill("lianhua-zhang",70);
	set_skill("huoyue-zaiyuan",70);
	map_skill("strike","huoyuan-zaiyuan");
	prepare_skill("strike", "huoyuan-zaiyuan");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
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
	if( ob->query("combat_exp") < 30000 ) return;
	command("say 你很爱打架吧？ 哈哈哈，好吧，我就收下你了！");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
