// /kungfu/class/xueshan/lazhang.c  拉章活佛 
// by secret 
 
#include <ansi.h>
#include "xueshan.h";
 
inherit NPC; 
inherit F_MASTER; 

string ask_for_join();

void create() 
{ 
	set_name("拉章活佛", ({ "lazhang huofo", "huofo", "lazhang" })); 
	set("long",@LONG 
拉章活佛是雪山寺有道的高僧，对佛法有精深的研究。 
他身穿一件黄色袈裟，头带僧帽。慈眉善目，似乎手无缚鸡之力。 
LONG 
	); 
	set("title",HIY"活佛"NOR); 
	set("gender", "男性"); 
	set("age", 50); 
	set("attitude", "peaceful"); 
	set("shen_type", -1); 
	set("str", 30); 
	set("int", 30); 
	set("con", 30); 
	set("dex", 30); 
	set("max_qi", 1000); 
	set("max_jing", 2500); 
	set("neili", 2000); 
	set("max_neili", 2000); 
	set("jiali", 50); 
	set("combat_exp", 400000); 
	set("score", 40000); 
 
	set_skill("lamaism", 130); 
	set_skill("literate", 120); 
	set_skill("force", 100); 
	set_skill("xiaowuxiang", 100); 
	set_skill("dodge", 120); 
	set_skill("shenkong-xing", 180); 
	set_skill("unarmed", 140); 
	set_skill("yujiamu-quan", 210); 
	set_skill("parry", 120); 
	set_skill("sword", 100); 
	set_skill("mingwang-jian", 150); 
 
	map_skill("force", "xiaowuxiang"); 
	map_skill("dodge", "shenkong-xing"); 
	map_skill("unarmed", "yujiamu-quan"); 
	map_skill("parry", "mingwang-jian"); 
	map_skill("sword", "mingwang-jian"); 
	
	set("no_get",1);
 
	create_family("雪山寺", 3, "活佛"); 
	set("class", "lama"); 

	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
	]));

	setup(); 
 
	carry_object("/d/xueshan/obj/y-jiasha")->wear(); 
	carry_object("/d/xueshan/obj/sengmao")->wear(); 
 
	add_money("silver",100);
} 
 
 
void attempt_apprentice(object ob) 
{ 
 
	if ((string)ob->query("gender") != "男性") { 
		command("say 修习密宗内功需要纯阳之体。"); 
		command("say 这位" + RANK_D->query_respect(ob) + 
			"还是请回吧！"); 
		return; 
	} 
 
	if ((string)ob->query("class") != "lama") { 
		command("say 我西藏黄教门内的清规戒律甚多。");
		command("say 这位" + RANK_D->query_respect(ob) + 
			"还是请回吧！");
		ob->set_temp("pending/join_bonze", 1);
		command("say 施主若真心皈依我佛，就请跪下(kneel)受戒。\n");

		return; 
	} 
 
	if ((string)ob->query("family/family_name") != "雪山寺")	{ 
		command("say 这位" + RANK_D->query_respect(ob) + 
			"既非本寺弟子，还是请回吧！");
		command("say 这位" + RANK_D->query_respect(ob) + 
			"不如先跟葛伦布师傅学习？");

		return; 
	} 
 
	if ((int)ob->query_skill("lamaism", 1) < 50) { 
		command("say 入我雪山寺，修习密宗心法是首要的。"); 
		command("say 这位" + RANK_D->query_respect(ob) + 
			"是否还应该多多钻研本门的心法？");

		return; 
	} 
 
	command("smile"); 
	command("nod"); 
	command("say 你就随我学习佛法吧！"); 
	command("recruit " + ob->query("id")); 
 
	ob->set("title",HIY"大喇嘛"NOR); 
}

void init()
{
	add_action("do_kneel", "kneel");
}
