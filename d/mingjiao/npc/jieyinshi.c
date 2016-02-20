// JieYinShi

#include "ansi.h"

inherit NPC;
inherit F_UNIQUE;

string ask_for_join();

void create()
{
	set_name("接引使", ({"jieyin shi","jieyin","shi",}));
	set("long",
		"他是一位精明的中年人，身穿一件白布长袍。\n"
		"他正在上下打量着你。\n"
		);

	set("gender", "男性");
	set("attitude", "friendly");

	set("inquiry",([
		"明教"	: (: ask_for_join :),
	]));

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan-yiqi", 30);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("jingang-quan", 50);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");
	set("party/party_name",HIG"明教"NOR);
	set("party/rank",HIY"总坛" NOR "教众");

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}



string ask_for_join()
{
	return "有介绍信就可以加入我明教。\n";
}

int accept_object(object ob, object obj)
{
	object me ;
	string men ;
	mapping party;

	me = this_object () ;
	ob = this_player () ;

	if (obj->query("id") == "tuijian xin1" && ob->query_temp("have_letter") )
	{
	  if(  ob->query("party") && ob->query("party/party_name") != HIG "明教" NOR )
	  {
	  	message_vision("$N摇摇头，对$n说道：你已经加入其他帮会了，不能再入我明教。\n",me,ob);
	  	return 1;
	  }
   	if( !mapp(party = ob->query("party")) && present("tuijian xin1", ob ))
   	{
		if ( (string)ob->query("gender") == "女性" ) men="地";
		else if ( (string)ob->query("class")=="taoist" 
		  || (string)ob->query("class")=="bonze" ) men="风";
		else if ( ob->query("shen") < 0 ) men="雷";
		else men="天";

		ob->delete_temp("have_letter");

		if ( (string)ob->query("gender") == "女性" )
			command("say 我明教又得一女中豪杰，真是可喜可贺！");
		else 
			command("say 我明教又得一英雄好汉，真是可喜可贺！");

		party = allocate_mapping(5);
		party["party_name"] = HIG "明教" NOR;
		party["rank"] = men+"字门教众";
		party["level"] = 1;
		party["tasks"] = 0;
		party["enter_time"] = time();
		ob->set("party", party);

		command("smile");
		message_vision("接引使对$N说道：恭喜$N成为明教"+men+"字门教众！\n",ob);
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
   	if( party["party_name"] != HIG "明教" NOR )
	{
		message_vision("接引使对$N摇摇头，说道：$N已经加入其他帮会了，不能再入我明教。\n",me,ob);
		return 1;
	}
	else
		message_vision("$N摇摇头，对$n说道：你已经是我明教的人了。\n",me,ob);
	}
        command("?");
        command("say 这东西给我可没有什麽用。");
	return 0;

}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
