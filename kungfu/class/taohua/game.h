// 拣竹签游戏，每次拿1-3根，拿到最后一根的输

#define		MATCHNUM	15	
#define		MAXNUM		3
#define 	obname  ob->query("name")
#define 	REMAIN	me->query_temp("match_game/remain")

int play_game( object me, object ob )
{
	me->set_temp("match_game/turn", 1);
	me->set_temp("match_game/remain",MATCHNUM);
	me->set_temp("match_game/last",0);
	me->set_temp("match_game/playing",1);
	message_vision(obname+"不知从哪里拿出几根竹签摆在桌子上。\n", me);
	command("say 这里有"+chinese_number(MATCHNUM)+"根竹签，每次最多拿三根，最少一根，不能不拿。谁拿到最后一根算输。");
	command("say 你先拿吧。\n");
	add_action("take_match","take");
	write(YEL +"你可以用 take + 根数 来玩。\n\n"+ NOR);
	return 1;
}


int take_match(string arg)
{
	int n;
	object me = this_player();
	object ob = this_object();
	
	if (me->query_temp("match_game/win") || me->query_temp("match_game/lost"))
		return 	notify_fail("游戏已经结束了。\n\n");
	n = atoi(arg);
	if (!intp(n))
		return notify_fail("你要拿什么？\n");
	if (n > MAXNUM || n <= 0)
		return notify_fail("一次只能拿一到"+chinese_number(MAXNUM)+"根竹签。\n");
	if (n > REMAIN) 
		return notify_fail("只剩下"+chinese_number(REMAIN)+"根竹签了。\n");
	me->add_temp("match_game/remain", -n);
	message_vision("$N拿了"+chinese_number(n)+"根竹签\n", me);
	if (REMAIN == 0) {
		message_vision(WHT +"没有竹签了，$N输了。\n"+ NOR, me);
		message_vision(obname+"笑着拍着手，对$N叫到：你好笨喔，你输啦！\n\n", me);
		me->set_temp("match_game/lost", 1);
		me->delete_temp("match_game/playing");
		return 1;		
	}
	else {
		message_vision("还剩下"+chinese_number(REMAIN)+"根竹签。\n\n", me);
		for (n = REMAIN; n > MAXNUM; n = n - MAXNUM - 1);
		n = (n + 3) % 4;
		if (n == 0)
		   	n = (REMAIN > MAXNUM ? random(MAXNUM)+1 : random(REMAIN)+1); 
		me->add_temp("match_game/remain", -n);	
		message_vision(obname+"拿了"+chinese_number(n)+"根竹签。\n", me);
		if (REMAIN != 0) {
			if (REMAIN == 1) {
				me->set_temp("match_game/lost",1);
				me->delete_temp("match_game/playing");
				message_vision(WHT +"还剩下"+chinese_number(REMAIN)+"根竹签，$N输了。\n"+ NOR, me);
				message_vision(obname+"笑着拍着手，对$N叫到：你好笨喔，你输啦！\n\n", me);
				return 1;
			}
			else				
				message_vision("还剩下"+chinese_number(REMAIN)+"根竹签，该$N拿了。\n\n", me);
		}
		else {
			message_vision(HIW +"没有竹签了，$N赢了。\n"+ NOR, me);
			message_vision(obname+"看了看手里的竹签又看了看$N，说道：是你瞎猫碰着死耗子，便宜你了。\n\n", me);
			me->set_temp("match_game/win", 1);
			me->delete_temp("match_game/playing");
			return 1;
		}
	}
	return 1;
}
