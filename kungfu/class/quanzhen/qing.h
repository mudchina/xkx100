// qing.h 出家和清字辈收徒和推荐给志字辈

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("quanzhen letter1", ob) ) 
	{
		command("say 怎麽样，你拿我的推荐信去拜师了吗 ?");
		return 0;
	}

	if((obj->query("id") == "quanzhen ling")
	&& ob_fam["family_name"] == "全真教"
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok",1);
	        command("say 好，既然已有掌门真人许可，我们就来验证一下武功。");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
        
	command("smile");
	command("say 这东西给我可没有什麽用。");
	command("give " + obj->query("id") + " to " + me->query("id"));
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
		command("say 青出於蓝胜於蓝，不愧是全真门下弟子！恭喜你了！\n");
		message_vision("$N交给$n一封推荐信。\n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new("/d/quanzhen/obj/tuijianxin-1");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say 看来" + RANK_D->query_respect(ob) + "还得多加练习，方能在本教诸多弟子中出人头地！\n");
		return 1;
	}

	return 1;
}

string ask_for_join()
{
	object me = this_player();
	mapping my_fam = me->query("family");

	if( (string)me->query("class")=="quanzhen" )
		return "无量寿佛！你我同属玄门，何故跟小道开这等无聊玩笑？\n";

	if( my_fam["family_name"] == "全真教" && my_fam["generation"] <= 4) 
		return "无量寿佛！玄门清修之士，应自小开始修行。\n";

	if( me->query("betrayer") > 0) 
		return "无量寿佛！你生性反复无常，非我玄门清修之士之所为。\n";

	me->set_temp("pending/join_quanzhen", 1);
	return "无量寿佛！施主若真心皈依我全真教门，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
	object me = this_player();

	string name, new_name;
	if( !me->query_temp("pending/join_quanzhen") ) return 0;

	message_vision(
		"$N右手捏着莲花指，恭恭敬敬地磕下头去。\n\n"
		"$n伸出双手，将$N头顶长发挽成一个道髻。\n\n",me,this_object());
	name = me->query("name");
	new_name = name[0..1] + "静" + name[2..3];
	command("say 从今以后你的道法号就叫做" + new_name + "。");
	command("smile");
	me->delete_temp("pending/join_quanzhen");
	me->set("name", new_name);
	me->set("class", "quanzhen");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
	me->set("shen", 0);

	return 1;
}

void attempt_apprentice(object ob)
{
	object me = this_object();
	mapping ob_fam;
	mapping my_fam = me->query("family");

	if ((int)ob->query("shen") < 0) {
		command( "say 行侠仗义是我辈学武人的基本品质，你已快入魔道，我岂能收你为徒。\n");
		return;
	}
	if (ob->query("gender")=="男性" && me->query("gender")=="女性")
	{
		command("say 我不收男徒，你还是去拜我几位师兄为师吧。\n");
                return;
	}

	if (ob_fam = ob->query("family"))
	{
		if( ob_fam["generation"] <= my_fam["generation"] &&
		    ob_fam["family_name"] == my_fam["family_name"] )
		{
			command("say "+RANK_D->query_respect(ob)+"，这个贫道哪敢当！");
			return;
		}
	}
	if( (string)ob->query("class")!="quanzhen" )
	{
		command ("say 无量寿佛！贫道就收下你做『俗家弟子』了。");
	}
	else
	{
		command ("say 无量寿佛！贫道就收你为全真教正式弟子。");
	}
	command("recruit " + ob->query("id"));
}

