// da.h 大字辈收徒
void attempt_apprentice(object ob)
{
	object me=this_object(); 
	mapping ob_fam, my_fam;
	string name, new_name;
	my_fam =me->query("family");
	name = ob->query("name");

	if(!(ob_fam=ob->query("family")) || ob_fam["family_name"]!="南少林派")
	{
		command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
		return;
	}
	if( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say "+RANK_D->query_respect(ob)+"，贫僧哪里敢当！");
		return;
	}
	if( ob->query_skill("force", 1) < 60)
	{
		command("say "+RANK_D->query_respect(ob)+"，你的基本内功还需要磨练。贫僧到时再收你为徒。");
		return;
	}
	if( ob->query_skill("zhanzhuang-gong", 1) < 60)
	{
		command("say "+RANK_D->query_respect(ob)+"，你的站桩功还需要磨练。贫僧到时再收你为徒。");
		return;
	}
	if( ob_fam["generation"]==(my_fam["generation"]+1) )
	{
		command("say "+ob_fam["master_name"]+"的徒弟怎么跑到我这儿来了，哈哈哈！");
		command("recruit "+ob->query("id"));
	}
	if( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		command("say 老衲得一可塑之才，真是老怀大畅。");
		command("recruit " + ob->query("id"));
		if( ob->query("class") == "bonze")
		{
			name = ob->query("name");
			new_name = "元" + name[2..3];
			ob->set("name", new_name);
			command("say 今后你的法名叫做"+new_name+"。\n");
		}
		else ob->set("title", "南少林俗家第二十弟子");
	}
	else
		command("say "+RANK_D->query_respect(ob)+"，你是从哪蹦出来的，你不能越级拜师。");
	return;
}

