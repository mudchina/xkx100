// fawang.h for fight and get letter from FaWang

void attempt_apprentice(object ob)
{
	object me = this_object();

	if (ob->query("party/party_name") != HIG "明教" NOR)
	{
		command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此话从何谈起？");
		return;
	}
	else
	{
		command("say 本法王又得一可塑之才，真是可喜可贺 !");
		command("recruit " + ob->query("id"));
//		ob->set("title", HIR"明教护法"NOR);
	}
	return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
		       	command("say 恭喜你荣升为明教护法！");
 				    ob->set("title", HIR"明教护法"NOR);
 				  }
}
#include "mingjiao.h"
