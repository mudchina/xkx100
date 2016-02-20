// shenjiao.h 入教
int do_join(object ob, object obj)
{
	object me;
	string pname ;
	mapping party;
	string *partyname = ({ HIG"青龙", HIW"白虎", HIC"风雷" });

	me = this_object () ;
	ob = this_player () ;

	if(ob->query("party") && ob->query("party/party_name")==HIB"日月神教"NOR)
	{
		message_vision("$N摇摇头，对$n说道：你已经是我神教的人了。\n",me,ob);
		return 1;
	}
	if(ob->query("party") && ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		message_vision("$N摇摇头，对$n说道：你已经加入其他帮会了，不能再入我日月神教。\n",me,ob);
		return 1;
	}
   	if( !mapp(party = ob->query("party")) )
   	{
		if ( (string)ob->query("gender") == "女性" ) pname=HIM"天香";
		else pname=partyname[random(sizeof(partyname))];
		if ( (string)ob->query("gender") == "女性" )
			command("say 我神教又得一女中豪杰，真是可喜可贺 !");
		else 
			command("say 我神教又得一英雄好汉，真是可喜可贺 !");

		party = allocate_mapping(5);
		party["party_name"] = HIB "日月神教" NOR;
		party["rank"] = pname+"堂教众"NOR;
		party["level"] = 1;
		party["tasks"] = 0;
		party["enter_time"] = time();
		ob->set("party", party);

		command("smile");
		message_vision("$N对$n说道：我渡你入教，你暂时先编入神教"+pname+"堂！\n", me, ob);
		return 1;
	}
        command("?");
        command("say 这东西给我可没有什麽用。");
	return 0;

}

