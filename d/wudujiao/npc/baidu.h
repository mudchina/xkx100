// baidu.h

int do_train(string arg)
{
	object me,who;
	me =this_object();
	who=this_player();
	if (!arg || (arg != me->query("id")))
		return notify_fail("你要驯服什么？\n");

	if(me->is_fighting())
		return notify_fail(me->query("name")+"正在战斗中。\n");

	if((string)who->query("family/family_name")!="五毒教")
		return notify_fail("什么？\n");

	if ((int)who->query_skill("wudu-shengong", 1) < 20) {
		return notify_fail("你的五毒神功还是不够啊？\n");
	}

	message_vision("$N对$n一阵怪啸：大胆，还不驯服更待何时？\n\n", who,me);
	message_vision("$N勃然大怒道：咱们谁驯谁还不一定哪？！\n$N冲上来和$n扭打到一起。\n",me,who);
	me->kill_ob(who);
	who->kill_ob(me);
	COMBAT_D->do_attack(me, who, query_temp("weapon"));
	if( (int)(me->query("combat_exp")/5) < who->query("combat_exp"))
		me->set("owner",who->query("id"));
	return 1;
}

void die()
{
	string owner,name,id;
	object owner_ob;
	object ob;
	owner = query("owner");
	if(owner) owner_ob= find_player(owner);

	if(owner_ob && (object)query_temp("last_damage_from") == owner_ob)
	{
		message_vision("$N趴在地上，一动也不敢动了。\n",this_object()); 
		switch (this_object()->query("id"))
		{
			case "du she": 
				 ob=new(__DIR__"she1.c");
				 break;
			case "zhi zhu": 
				 ob=new(__DIR__"zhizhu1.c");
				 break;
			case "wu gong": 
				 ob=new(__DIR__"wugong1.c");
				 break;
			case "xie zi": 
				 ob=new(__DIR__"xiezi1.c");
				 break;
			case "chan chu": 
				 ob=new(__DIR__"chanchu1.c");
				 break;
		}
		ob->move(environment(owner_ob));
		ob->set_leader(owner_ob);
		ob->set("host_id",owner_ob->query("id"));
		name=this_object()->query("name");
		id=this_object()->query("id");
		ob->set_name(name,({id}));
		destruct(this_object());

		return;
	}
	else {
		message_vision("$N倒在地上，死了！\n", this_object());
		switch (this_object()->query("id"))
		{
			case "du she": 
				 ob=new(__DIR__"obj/shedu.c");
				 break;
			case "zhi zhu": 
				 ob=new(__DIR__"obj/zhizhudu.c");
				 break;
			case "wu gong": 
				 ob=new(__DIR__"obj/wugongdu.c");
				 break;
			case "xie zi": 
				 ob=new(__DIR__"obj/xiezidu.c");
				 break;
			case "chan chu": 
				 ob=new(__DIR__"obj/chanchudu.c");
				 break;
		}
		ob->move(environment(this_object()));
		destruct(this_object());
	}
}

