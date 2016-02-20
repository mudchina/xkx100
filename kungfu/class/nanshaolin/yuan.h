// Last Modified by winder on May. 29 2001
// yuan.h 元字辈收徒

int do_nod();
void attempt_apprentice(object ob)
{
        mapping fam;

	if(!mapp(fam = ob->query("family")) || fam["family_name"]!="南少林派")
	{
		command("say 我只收本派弟子为徒。\n");
		return;
	}
	if(fam["generation"] < 21)
	{
		command("say 阿弥陀佛。我佛慈悲。\n");
		return;
	}
	ob->set_temp("wait_nod", 1);
	command("say 依照南少林寺历代规矩，"+RANK_D->query_respect(ob)+"你必须接下我三招，我才能收你为徒。你愿意么？那就点个头吧(nod)。");
}
int do_nod()
{
	object ob = this_player();

	if(!ob->query_temp("wait_nod")) return 0;
	ob->delete_temp("wait_nod");
	call_out("test", 1, ob);
	return 0;
}
void test(object ob)
{
	object me=this_object();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
//	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
//	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	call_out("check", 1, ob);
}

void check(object ob)
{
	string new_name;

	if (!living(ob) || environment(ob) != environment() ||
		ob->query("max_qi") > ob->query("qi") * 2)
	{
		command("sigh");
		return;
	}
	else
	{
		command("recruit " + ob->query("id"));
		if( ob->query("class") == "bonze")
		{
			new_name=ob->query("name");
			new_name[0..1] = "方";
			ob->set("name", new_name);
			command("say 从今以后你的法名叫做"+new_name+"吧！\n");
		}
		else ob->set("title", "南少林俗家第二十一弟子");
	}
	return;
}
