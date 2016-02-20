// gaibang.h for fight and get 青竹令

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam = me->query("family");
	mapping ob_fam = ob->query("family");

	if (!ob_fam || (ob_fam["family_name"] != "丐帮"))
	{
		command("say 你哪里来的青竹令？\n");
		return 0;
	}

	if ( ob->query_temp("have_cloth") || present("po bu", ob) )
	{
		command("say 你不是已经有破布么?");
		return 0;
	}

	if (((ob->query("beggarlvl") == 0) &&
		(ob->query("combat_exp") <= 500)) ||
		((ob->query("beggarlvl") == 1) &&
		(ob->query("combat_exp") <= 1000)) ||
		((ob->query("beggarlvl") == 2) &&
		(ob->query("combat_exp") <= 3000)) ||
		((ob->query("beggarlvl") == 3) &&
		(ob->query("combat_exp") <= 5000)) ||
		((ob->query("beggarlvl") == 4) &&
		(ob->query("combat_exp") <= 10000)) ||
		((ob->query("beggarlvl") == 5) &&
		(ob->query("combat_exp") <= 15000)) ||
		((ob->query("beggarlvl") == 6) &&
		(ob->query("combat_exp") <= 20000)) ||
		((ob->query("beggarlvl") >= 7) &&
		(ob->query("combat_exp") <= 30000)))
	{
		command("say 就你那点脓水？我看就算了吧。\n");
		return 1;
	}
	if (((ob->query("beggarlvl") == 0) &&
		(me->query("beggarlvl") == 1)) ||
		((ob->query("beggarlvl") == 1) &&
		(me->query("beggarlvl") == 2)) ||
		((ob->query("beggarlvl") == 2) &&
		(me->query("beggarlvl") == 3)) ||
		((ob->query("beggarlvl") == 3) &&
		(me->query("beggarlvl") == 4)) ||
		((ob->query("beggarlvl") == 4) &&
		(me->query("beggarlvl") == 5)) ||
		((ob->query("beggarlvl") == 5) &&
		(me->query("beggarlvl") == 6)) ||
		((ob->query("beggarlvl") == 6) &&
		(me->query("beggarlvl") == 7)) ||
		((ob->query("beggarlvl") == 7) &&
		(me->query("beggarlvl") == 8)) ||
		((ob->query("beggarlvl") == 8) &&
		(me->query("beggarlvl") == 9)))
	{
		if((obj->query("id")=="qingzhu ling") && !ob->query_temp("have_cloth"))
		{
			ob->set_temp("fight_ok", me->query("beggarlvl"));
			command("say 好，既然已有青竹令，那就看你的运气了。\n");
			remove_call_out("destroying");
			call_out("destroying", 1, me, obj);
			return 1;
		}
	}
	command("smile");
	command("say 升袋当然只升不降。跳升也是不行的。\n");
	command("say 这东西给你还是自己留着吧。\n");
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
	object me = this_object();
	if ( ob->query("family/family_name") != "丐帮") return 0;
	if ( ob->query_temp("fight_ok") != me->query("beggarlvl") )
	{
		command("say 你是本帮"+chinese_number(ob->query("beggarlvlk"))+"，不能向我挑战！\n");
		return 0;
	}

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	ob->delete_temp("fight_ok");
	return 1;
}

int checking(object me, object ob)
{
	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting())
	{
		call_out("checking",2, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1;

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
	{
		command("say 大爷今天心情好，算你运气。拿这块破布找简长老去！\n");
		message_vision("$N交给$n一块破布。\n", me, ob);
		ob->set_temp("have_cloth",1);
		obj=new(__DIR__"obj/po-bu");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
	{
		command("say 看来" + RANK_D->query_respect(ob) + "想升袋？也不掂量掂量自家的斤两！\n");
		return 1;
	}
	return 1;
}

