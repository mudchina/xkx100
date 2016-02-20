// paitong.c 牌童

# include <ansi.h>
inherit NPC;
int pieqian(object me);
int pieshuang(object me);
int do_deal();
int do_turn();
int yesorno();
string cstr(int i);

//全程变量
int sumi,summ;
int thecash;
int m1,m2,m3,i1,i2,i3,j1,j2,j3,k1,k2,k3;

void create()
{
	set_name("牌童", ({ "pai tong", "paitong", "kid" }));
	set("gender", "男性");
	set("long",
		"这是一个牌场小厮。\n"
	);
	set("age", 32);
	set("no_get", 1);
	set("immortal",1);

	set("inquiry", ([
		"赌"   : "要赌就赌，和我罗嗦？没空没空。\n",
		"押牌" : "快押快押，先给钱再押。别磨蹭。\n",
	]) );
	set("book_count",1);
	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_deal","deal");
	add_action("do_turn","turn");
}

int accept_object(object who, object ob)
{
	object obj;
	object me=this_player();

	if (me->is_busy())
		return notify_fail("你还在忙着呢，等一会吧。");
	me->start_busy(5);
	if (query("book_count"))
	{
		if (ob->query("money_id"))
		{
			if (ob->query_temp("tmark/押"))
			{
				message_vision( HIG"牌童诧异地对$N说：你已经下过注了呀！\n"NOR,who);
				return 0;
			}
			if (ob->value()<100)
			{
				message_vision( HIR"牌童不屑一顾地看着$N，说道：要下注至少一两银子！\n"NOR,who);
				return 0;
			}
			if (ob->value()>20000)
			{
				message_vision( HIR"牌童摇了摇头，对$N说道：这里不欢迎孤注一掷，最多下二两黄金。\n"NOR,who);
				return 0;
			}
			add("book_count",-1);
			thecash = ob->value();
			who->set_temp("tmark/押",1);
			sumi=summ=0;
			i1=i2=i3=m1=m2=m3=j1=j2=j3=k1=k1=k3=0;
			message_vision( HIY"牌童吆喝道：$N下注完成，发牌了。\n"NOR,who);
			i1 = 1+random(13);
			i2 = 1+random(13);
			message_vision( WHT"庄家的牌是:    ？   和   "HIG+cstr(i1)+"\n"NOR,who);
			if (i1>10) j1=10; else j1=i1;
			if (i2>10) j2=10; else j2=i2;
			sumi = j1 + j2;

			m1 = 1+random(13);
			m2 = 1+random(13);
			message_vision( WHT"\n你的牌是:    "HIR+cstr(m1)+WHT"   和   "HIR+cstr(m2)+"\n"NOR,who);
			if (m1>10) k1=10; else k1=m1;
			if (m2>10) k2=10; else k2=m2;
			summ = k1+k2;
			if ((summ == 21) || ((summ==11) && (m1==1 || m2==1)) )
			{
				message_vision(HIG"啊！BLACKJACK，你真厉害，还得赔你双倍！我呸！\n"NOR,who);
				remove_call_out("destroying");
				call_out("destroying", 0, me, ob);
				pieshuang(who);
				set("book_count",1);
			}
			else
			{
				message("vision", HIW"如果还要牌，请键入 deal,否则请键入 turn。\n"NOR,who);
			}

			remove_call_out("destroying");
			call_out("destroying", 0, me, ob);
			return 1;
		}
	}
	else
	{
		message_vision("已经有人在牌童对赌了，看来$N得等下一拨了。\n",who);
		return 0;
	}
}

int do_deal()
{
	object me=this_player();
	int m3;

	if (!me->query_temp("tmark/押"))
	{
		message_vision( MAG"牌童不耐烦地推了$N一把：去去去，注还没下呢，押什么牌啊！\n"NOR,me);
		return 1;
	}
	m3 = 1+random(13);
	message("vision", HIM"你还要一张啊，好吧，给你这张牌:   "HIR+cstr(m3)+"\n"NOR,me);
	if (m3>10) k3=10; else k3=m3;
	summ = summ+k3;
	if(m1==1 || m2==1 || m3==1)
		if(summ<12) summ=summ+10;

	if (summ>21)
	{
		message_vision( WHT"牌童笑嘻嘻地说：不好意思，你的牌涨爆了，我又赢了。\n"NOR,me);
	}
	else
	{
		if (summ==21)
		{
			message_vision( HIW"牌童面如土色：又是２１点？你奶奶的，害老子赔双倍！\n"NOR,me);
			pieshuang(me);
		}
		else
		{
			sumi = yesorno();
			if(i1==1 || i2==1 || i3==1)
			{
				if(sumi<12) sumi=sumi+10;
				if(sumi>21) sumi=sumi-10;
			}

			if (sumi>21 || sumi<summ)
			{
				if (sumi>21)
					message_vision( HIY"牌童丧气地说：我的"HIG+cstr(i1)+cstr(i2)+cstr(i3)+HIY"涨爆了，天灾人祸，赔你！\n"NOR,me);
				else
					message_vision( HIY"牌童气得一把把牌扔在桌上：我"HIG+cstr(i1)+cstr(i2)+cstr(i3)+HIY"，你点大，给你钱！撑死你！\n"NOR,me);
				pieqian(me);
			}
			else
			{
				if (sumi == summ)
				{
					message("vision", HIG"牌童贼兮兮的道：不好意思，我是"HIR+cstr(i1)+cstr(i2)+cstr(i3)+HIG"，同点庄家吃了。\n"NOR,me);
				}
				else
				{
					message_vision( HIG"牌童笑嘻嘻地说：我的牌是"HIR+cstr(i1)+cstr(i2)+cstr(i3)+"\n"NOR,me);
					message_vision( HIG"牌童满脸遗憾的表情：大家这么熟的朋友了，怎么能老赢你的钱呢？怪不好意思！\n"NOR,me);
				}
			}
		}
	}

	me->set_temp("tmark/押",0);
	set("book_count",1);
	return 1;
}

int do_turn()
{
	object me = this_player();
	if (!me->query_temp("tmark/押"))
	{
		message_vision( HIY"牌童不耐烦地推了$N一把：去去去，注还没下呢，押什么牌啊！\n"NOR,me);
		return 1;
	}

	summ = summ+k3;
	if(m1==1 || m2==1 || m3==1)
		if(summ<12) summ=summ+10;

	sumi = yesorno();
	if(i1==1 || i2==1 || i3==1)
	{
		if(sumi<12) sumi=sumi+10;
		if(sumi>21) sumi=sumi-10;
	}

	if (sumi>21 || sumi<summ)
	{
		if (sumi>21)
			message_vision( HIY"牌童丧气地说：我的牌"HIG+cstr(i1)+cstr(i2)+cstr(i3)+HIY"涨爆了，亏大了人家我，赔你！\n"NOR,me);
		else
			message_vision( HIY"牌童气得一把把牌扔在桌上：我是"HIG+cstr(i1)+cstr(i2)+cstr(i3)+HIY"，算你走运！\n"NOR,me);
		pieqian(me);
	}
	else
	{
		if (sumi == summ)
		{
			message_vision( HIG"牌童贼兮兮的道：不好意思，我是"HIR+cstr(i1)+cstr(i2)+cstr(i3)+HIG"，同点庄家吃了。嘿嘿嘿...\n"NOR,me);
		}
		else
		{
			message_vision( HIG"牌童笑嘻嘻地说：我的牌是"HIR+cstr(i1)+cstr(i2)+cstr(i3)+"\n"NOR,me);
			message_vision( HIG"牌童满脸遗憾的表情：大家这么熟的朋友了，赢你的钱别不开心了！\n"NOR,me);
		}
	}

	me->set_temp("tmark/押",0);
	set("book_count",1);
	return 1;
}

int pieqian(object me)
{
	object ob,ob1;

	if(thecash<10000)
	{
		ob = new("/clone/money/silver");
		ob->set_amount(thecash/100*2);
		ob->move(me);
	}
	else
	{
		ob = new("/clone/money/gold");
		ob->set_amount(thecash/10000*2);
		ob->move(me);
		if((thecash % 10000)!=0)
		{
			ob1 = new("/clone/money/silver");
			ob1->set_amount((thecash-((thecash/10000*10000)))/100*2);
			ob1->move(me);
		}
	}
	me->set_temp("tmark/押",0);
	return 1;
}

int pieshuang(object me)
{
	object ob,ob1;

	if(thecash<10000)
	{
		ob = new("/clone/money/silver");
		ob->set_amount(thecash/100*3);
		ob->move(me);
	}
	else
	{
		ob = new("/clone/money/gold");
		ob->set_amount(thecash/10000*3);
		ob->move(me);
		if((thecash % 10000)!=0)
		{
			ob1 = new("/clone/money/silver");
			ob1->set_amount((thecash-((thecash/10000)*10000))/100*3);
			ob1->move(me);
		}
	}
	me->set_temp("tmark/押",0);
	return 1;
}

int yesorno()
{
	object me=this_player();

	if (i1==1 || i2==1)
		if(sumi<12) sumi=sumi+10;

	if (sumi>17) return sumi;
	else
	{
/* 似乎这个概率不太对 by xmmy

是关于押牌房(就是赌21点)的一个大bug。
在赌21点的时候，系统是设置让牌童在拿到的牌在小于15点的时候就继续要牌，
大于等于15点的话：
                如果玩家两张牌的点数大于牌童的点数，还是继续要牌，
                如果玩家的点数比牌童的点数小，牌童就直接摊牌。
这个算法其实并不是最优策略。
通过计算可以发现（具体计算太复杂，因为要考虑A既可以算1点，也可以算11点
的情况，我是先不考虑A可以算11点的情况，算出有问题，再通过实践来验证的），
在大于等于16点的时候才摊牌是最佳的选择。呵呵，具体的计算过程我就不发过来了，

如果你要的话，我再打给你（因为我是在纸上算的）。
附上我实践的一些数据：
   我的机器人是设置成如果我的牌小于16点就继续要牌，大于等于16点就摊派。
   长安、扬州两处押牌房一起挂，从晚上12点到早上7点，一般可以赚七万到八万gold。
   我挂机纪录的数据：win=39655,lost=37310,
   win就是赢的次数(如果刚好21点赢双份的话我是算赢两次的)， lost就是输的次数。
建议吧押牌的程序改成牌童在大于等于16点的时候才摊牌，这样子就不会再有bug了。
btw:呵呵，我的bug没有让别人知道的，所以不用担心会出现旧站的时候cash满天飞的情
况。
    我的钱现在有二三十万吧（因为我只用过几次，赚太多了也没意思），我会注意控
制我的钱的，
     不会引起mud系统的金钱混乱。
     xixi,那为什么我要把bug交出来呢？是因为上次做bug的时候被其他玩家看见了，
为了避免出现旧站的混乱，我就忍痛来报告了。当然啦，还是那句话，我是不要奖励的。
        作为xkx100的一个老玩家，能为xkx100做点贡献我认为很欣慰，总算没白跳进
泥潭一场!
		if (sumi<14)

*/
		if (sumi<15)
		{
			i3 = 1+random(13);
			if (i3>10) j3=10; else j3=i3;
			return sumi+j3;
		}
		else
		{
			if(random(21)>10)
			{
				i3 = 1+random(13);
				if (i3>10) j3=10; else j3=i3;
				return sumi+j3;
			}
			else return sumi;
		}
	}
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

string cstr(int i)
{
	switch(i) {
		case 1:
			return "Ａ";
		case 2:
			return "２";
		case 3:
			return "３";
		case 4:
			return "４";
		case 5:
			return "５";
		case 6:
			return "６";
		case 7:
			return "７";
		case 8:
			return "８";
		case 9:
			return "９";
		case 10:
			return "Ｔ";
		case 11:
			return "Ｊ";
		case 12:
			return "Ｑ";
		case 13:
			return "Ｋ";
		default:
			return "";
	}
}
