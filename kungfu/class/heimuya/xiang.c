// xiang.c
#include <ansi.h>
inherit NPC;
int ask_kill();

void create()
{
	set_name("向问天", ({ "xiang wentian", "xiang"}));
	set("nickname", HIR "天王老子" NOR );
	set("gender", "男性");
	set("long", "他就是日月神教的光明左使。为人极为豪爽。只见他容貌清癯，颏下疏疏朗朗一丛花白长须，垂在胸前。\n");
	set("age", 45);
	set("shen_type", 1);
	set("env/wimpy", 40);

	set("str", 21);
	set("per", 28);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("chat_chance", 1);
	set("inquiry", ([
		"杨莲亭"     : "这种人，该杀！\n",
		"东方不败"   : "篡位叛徒，我非杀了他不可！\n",
		"杀东方不败" : (: ask_kill() :),
		"任我行"     : "教主被困，已历十年......\n",
	]));
	set("count",1);
	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 350);

	set("combat_exp", 2500000);
	set("score", 0);

	set_skill("force", 200);            // 基本内功
	set_skill("finger", 200);           // 基本指法
	set_skill("dodge", 200);            // 基本躲闪
	set_skill("parry", 200);            // 基本招架
	set_skill("dagger", 200);           // 基本刺法
	set_skill("sword", 200);            // 基本剑法
        set_skill("shigu-bifa", 200);       // 石鼓打穴笔法
	set_skill("piaoyibu", 200);         // 飘逸步法
	set_skill("wuyun-jian", 200);       // 五韵七弦剑
	set_skill("xuantian-zhi", 200);	    // 玄天无情指
	set_skill("kuihua-xinfa", 200);	    // 葵花心法

	map_skill("force", "kuihua-xinfa");
	map_skill("sword", "wuyun-jian");
	map_skill("dagger", "shigu-bifa");
	map_skill("finger", "xuantian-zhi");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun-jian");

/*	set("inquiry", ([
		"日月神教" : "你想加入我日月神教，就得找四大堂长老。",
		"入教"     : "你想加入我日月神教，就得找四大堂长老。",
	]));
*/
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIR"第八代光明左使"NOR);
	create_family("黑木崖", 8, "弟子");

	setup();
	carry_object("/d/mingjiao/obj/baipao")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 向某独来独往，向不收弟子。\n");
	return;
}

int ask_kill()
{
	object ob,me = this_player();

	command("tell "+this_player()->query("id")+" 你要去杀东方不败？");
	if (query("count")>0)
	{
		add("count",-1);
	  message_vision(HIC "向问天对$N点了点头说：我助你一臂之力。\n" NOR,this_player());
	  ob=new("/d/heimuya/npc/obj/card4");
	  ob->move(me);
	  tell_object(me,"向问天从怀里摸出一块令牌塞到你的手上。\n");
	}
	return 1;
}
