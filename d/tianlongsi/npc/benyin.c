// benyin.c
inherit NPC;
inherit F_MASTER;

string ask_me();
void create()
{
	set_name("本因", ({ "ben yin","yin"}) );
	set("gender", "男性" );
	set("title", "天龙寺第十七代住持");
	set("long", "一个神情潇洒的僧人，他是天龙寺住持方丈。\n");
	set("class", "bonze");
	set("age", 43);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 800000);
	set("score", 1000000);

	set_skill("force", 120);
	set_skill("dodge", 180);
	set_skill("parry", 120);
	set_skill("finger", 185);
	set_skill("sword", 120);
	set_skill("tiannan-step", 180);
	set_skill("kurong-changong", 150);
	set_skill("duanjia-sword", 120);
	set_skill("six-finger", 180);
	set_skill("buddhism", 100);
	set_skill("literate", 80);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");
	set("inquiry" ,([
	"舍利子" : (:ask_me():),
	"六脉神剑谱" : "“施主不会是打什么主意吧？”\n",
	"六脉神剑" :  "“施主不会是想和我较量较量吧？”\n",
	]));

	create_family("大理段家",17,"高僧");
	setup();
	carry_object("/d/xueshan/obj/b-jiasha")->wear();
}

string ask_me()
{
	object me=this_player();
	if(me->query_temp("marks/ask_temp0"))
		{
		me->set_temp("marks/ask_temp1",1);
		return "“那是本寺的镇寺之宝，多年以前不慎丢失。施主如能找回此物，\n         老衲必有重谢。”\n";
		}
	else
		return "“施主不可妄言。”\n";
}

int accept_object(object who, object ob)
{
        if (  (string)ob->query("id") == "jin he")
	{
		message_vision("本因大喜道：“多谢施主！施主若是有缘人，请到牟尼堂取本寺之宝。\n", who);
		who->set_temp("marks/find_temp",1);
		who->move("/d/tianlongsi/banruotai");
		return 1;
	}
	return 0;
}
#include "ben.h"
