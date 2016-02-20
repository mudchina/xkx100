// ZhangQiShi.h for fight and get letter from ZhangQiShi

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	add_action("do_join","join");

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping ob_party  = ob->query("party");

	if ( ob->query_temp("have_letter") && present("tuijian xin3", ob) ) 
	{
		command("say 怎麽样，你拿我的推荐信去见堂主了吗 ?");
		return 0;
	}

	if((obj->query("id") == "tieyan ling")
    && ob_party["party_name"] == "明教"
	&& ob_party["level"] == 2
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok",1);
		command("say 好，既然已得到教主许可，我们就来验证一下武功。");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

	if (obj->query("id") == "tuijian xin2" 
	&& ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say 好，" + ob->query("name") + "，你愿意加入我旗吗？");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
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

int accept_fight(object ob)
{
	object me  = this_object();
	
	if ( !ob->query_temp("fight_ok") ) return 0;

	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	ob->delete_temp("fight_ok");
	
	return 1;
}

int checking(object me, object ob)
{

	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
                return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
                command("say 青出於蓝胜於蓝，不愧是我明教的佳弟子 ! 恭喜你了 !\n");
		message_vision("$N交给$n一封推荐信。\n", me, ob);
		ob->set_temp("have_letter",1);
                obj=new("/d/mingjiao/obj/tuijianxin-3");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say 看来" + RANK_D->query_respect(ob) + 
                        "还得多加练习，方能在明教诸多弟子中出人头地 !\n");
		return 1;
	}

	return 1;  
}

void do_join()
{
	object me,ob;
	mapping ob_party;
	string qi,new_rank;

	me=this_object();
	ob=this_player();

        if (!(ob_party=ob->query("party"))||ob_party["party_name"]!="明教")
	{
                command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此举是何用意？");
		return;
	}

	if ( ob_party["level"] <= me->query("level") )
	{
                command("say " + RANK_D->query_respect(ob) + "，在下哪里敢当 !");
		return;
	}

	if ( ob_party["level"] == 1 )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say 哈哈哈 !");
                        command("say 本旗又得一可塑之才，真是可喜可贺 !");

			qi = me->query("title")[11..30];

	        	command("say 恭喜你荣升为明教"+qi+"教众！");
			new_rank = qi + "教众";
                        ob->set(ob_party["rank"],new_rank);
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，你没有推荐信，不能越级拜师。");
			return;
		}
	}

	return;
}

#include "mingjiao.h"
