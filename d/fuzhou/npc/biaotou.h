#define lay_exp 20
#define lay_pot 5
#define price_exp 220
#define price_pot 50
int ask_jiaobiao()
{
	object me = this_player();
	object cart,biaotou,money,ob = this_object();
	int i, give_exp, give_pot,give_score;

	if (me->query_temp("fuwei_destm") != ob->query("id"))
	{
		message_vision(HIR"$N问$n道：“搞错了！搞错了！你怎么把给"+me->query_temp("fuwei_dest")+"分局的镖车送到我这来呢？”\n"NOR,ob,me);
		return 1;
	}
	if (! objectp(cart = present("cart", environment(me))))
	{
		message_vision("$N问$n道：“镖车呢？那上面可是有好几万镖银啊！”\n",ob,me);
		return 1;
	}
	if (! objectp(biaotou = present("biao tou", environment(me))))
	{
		message_vision("$N问$n道：“随队镖头呢？路上丢失人手，你还敢来见我！”\n",ob,me);
		return 1;
	}
	if (cart->query("guarded") != me->query("id"))
	{
		message_vision("$N看了看镖车，对$n说道：“这镖车不是你押的。你把镖车丢哪去了？”\n",ob,me);
		return 1;
	}
	if (biaotou->query("leader_name") != me->query("id"))
	{
		message_vision("$N指着$n说道：“我不是和他一路的，我不认识他。”\n",biaotou, me);
		return 1;
	}
	tell_object(me,HIW+ob->query("name")+"笑道：恭喜你成功将镖车送到目的地，完成了这项任务！\n\n"NOR);

        message("channel:chat", HIM"【谣言】听说"+cart->query("guardby")+"成功将镖车送到目的地了！\n"NOR,users());

	i = 0;
	give_exp = lay_exp * biaotou->query("total_steps");
	give_pot = lay_pot * biaotou->query("total_steps");
	while ( i < biaotou->query("combat_num") )
	{
		give_exp += (price_exp/2 + random(price_exp/2));
		give_pot += (price_pot/2 + random(price_pot/2));
		i++;
	}
        
	message_vision(YEL"$N长出了一口气道：“哎，终于到了。我可和伙计们喝酒去了。”\n"NOR,biaotou);
	message_vision(YEL"$N和"+me->query_temp("fuwei_dest")+"分局的趟子手们一阵粗言秽语、喊爹骂娘地勾肩搭背一拥出门去了。\n"NOR,biaotou);
	message_vision(HIC"镖车给"+me->query_temp("fuwei_dest")+"分局的伙计们推进了库房。\n\n"NOR,biaotou);
	destruct(biaotou);
	destruct(cart);

	if(give_exp > 5000) give_exp = 4000 + random(1000);
	if(give_pot > 1000 ) give_pot = 900 + random(100);
        give_score = 800 + random(400);
	money=new("/clone/money/gold");
	money->set_amount(40);
	money->move(me);

	tell_object(me, sprintf(HIR+ob->query("name")+"对"+me->query("name")+"称许道：“你被奖励了！得到%s点经验和%s点潜能和%s点江湖阅历。镖局发给你四十两黄金做你的薪金和补偿你的押金。”\n"NOR, chinese_number(give_exp),chinese_number(give_pot),chinese_number(give_score) ) + NOR);
	message_vision("$N给$n一些"YEL"黄金"NOR"。\n"NOR, ob, me);
	log_file("mission/ms_biaoche",sprintf("%20s做运送镖车任务，得到：%4i点EXP和%4i点潜能。\n",
       me->query("name")+"("+getuid(me)+")",give_exp,give_pot));
	me->add("combat_exp",give_exp);
	me->add("potential",give_pot);
  me->add("score",give_score);
	me->add("baobiao",1);
	ob->set_temp("prize_reason","运镖");
	ob->set_temp("can_give_prize",1);
	ob->set_temp("prize_exp",give_exp);
	ob->set_temp("prize_pot",give_pot);
	me->delete_temp("fuwei_destm");
	me->delete_temp("fuwei_dest");

	return 1;
}

