// ake.c

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

#define MAX_PAWN 10
void create()
{
	set_name("阿珂", ({ "a ke", "ke" }) );
	set("gender", "女性" );
	set("long", "阿珂为李自成与陈圆圆之女。
她容色丽都，冠绝当代，五根手指细长娇嫩，真如用白玉雕
成，手背上手指尽处，有五个小小的圆涡。
当年韦小宝一见这少女，不过十六七岁，胸口宛如被一个无
形的铁锤重重击了一记，霎时之间唇燥舌干，目瞪口呆，心
道：“我死了，我死了！哪里来的这样的美女？这美女倘若
给了我做老婆，小皇帝跟我换位也不干。韦小宝死皮赖活，
上天下地，枪林箭雨，刀山油锅，不管怎样，非娶了这姑娘
做老婆不可。”\n");
	set("age", 16);
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",30);
	set("no_get", 1);
	set("no_get_from", 1);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	setup();

	carry_object("/d/city/obj/flower_shoe")->wear();
	carry_object("/d/city/obj/green_cloth")->wear();
}

void init()
{
	add_action("do_value", "value");
//	add_action("do_pawn", "pawn");
//	add_action("do_redeem", "redeem");
}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "文钱";
	else
		return chinese_number(value/100) + "两" + (value%100? "又" + chinese_number(value%100) + "文钱": "");
}

void pay_player(object who, int amount)
{
	object ob;
	if( amount < 1 ) amount = 1;
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
	if( amount/100 ) {
		ob = new(SILVER_OB);
		ob->set_amount(amount/100);
		ob->move(who);
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int do_value(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("阿珂问道：“你要拿什麽物品给我估价？”\n");

	if( ob->query("money_id") )
		return notify_fail("阿珂问道：“这是「钱」，你没见过吗？”\n");

	value = ob->query("value");
	if( !value ) printf("阿珂道：“%s一文不值。”\n", ob->query("name"));
	else 
		printf("阿珂道：“%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果你到广陵当铺卖断(sell)，可以拿到%s。”\n", ob->query("name"), value_string(value), value_string(value * 25 / 100), value_string(value * 75 / 100));
	return 1;
}

int do_pawn(string arg)
{
	object ob;
	string term, *terms;
	string data;
	int value, pawn_count, i;
	int rvalue;
	mapping pawn;
	object me;
	me = this_player();
	pawn = me->query("pawn");
	if( !arg || !(ob = present(arg, this_player())) )
	{
		write("你目前典当的物品有：\n");
		if( !mapp(pawn) || !sizeof(pawn) )
			write("\t没有任何典当的物品。\n");
		else
		{
			terms = keys(pawn);
			for(i=0; i<sizeof(terms); i++)
			printf("%-3s：  %-15s  赎银：%s\n", terms[i], pawn[terms[i]], value_string(((int)me->query("vpawn/"+terms[i]))* 3/4));
		}
		return 1;
	}
	if( ob->query("money_id") )
		return notify_fail("阿珂问道：“你要当「钱」？”\n");
	if (ob->is_container() )
		return notify_fail("阿珂道：“"+ob->name()+"可以装东西，是不能收当的！请尊驾原谅。”\n");
	if( ob->query("ownmake") )
		return notify_fail("阿珂道：“典当的行规，对武林中人的吃饭家伙是不能收当的！请尊驾原谅。”\n");
	if( ob->query("shaolin") )
		return notify_fail("阿珂道：“少林庙产小店可不敢收！”\n");
	if( ob->query("equipped") || ob->query("no_drop") )
		return notify_fail("阿珂道：“这样东西可当不了！”\n");
	if( ob->is_character() )
		return notify_fail("阿珂客客气气地道：“典当的行规，活东西是不能当的，请尊驾原谅。”\n");
	value = ob->query("value");
	if( !(value/4) )
		return notify_fail("阿珂道：“这样东西并不值很多钱。”\n");

	if( mapp(pawn) && sizeof(pawn))
	{
		terms = keys(pawn);
		if(sizeof(terms) > MAX_PAWN)
			return notify_fail("阿珂道：“你已典当太多物品了。”\n");
		for(i=0; i<sizeof(terms); i++)	
		{
			pawn_count = i;
			if(!((int) me->query("vpawn/" + sprintf("%d", i))))
				break;
			else pawn_count = i+1;
		}
	}
	else pawn_count = 0;
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	me->set("pawn/"+ sprintf("%d",pawn_count),  term);
	me->set("vpawn/"+sprintf("%d",pawn_count), ob->query("value"));
	me->set("fpawn/"+sprintf("%d",pawn_count), data);
	me->save();
	message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
		+ value_string(value * 25 / 100) + "。\n", this_player());
	message_vision("阿珂提笔写道：“今押到"+ ob->query("name")+"一，残缺破烂，当" + value_string(value * 25 / 100)+"整。年息二分，凭票取赎。虫蚁鼠咬，兵火损失，各安天命，不得争论。三年为期，不赎断当。”递给了$N。\n", this_player());
	pay_player(this_player(), value * 25 / 100 );
	destruct(ob);

	return 1;
}

int do_sell(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要卖断什麽物品？\n");

	if( ob->query("money_id") ) return notify_fail("你要卖「钱」？\n");
	value = ob->query("value");
	if( !value ) return notify_fail("这样东西不值钱。\n");

	message_vision("$N把身上的" + ob->query("name") + "卖掉。\n", this_player());

	pay_player(this_player(), value  * 80 / 100);
	destruct(ob);

	return 1;
}
void pay_him(object who, int amount)
{
	object ob;
	object cash, tencash, gold, silver, coin;
	tencash = present("tenthousand-cash_money", who);
	cash = present("thousand-cash_money", who);
	gold = present("gold_money",who);
	silver = present("silver_money",who);
	coin = present("coin_money",who);
	if(tencash) destruct(tencash);
	if(cash) destruct(cash);
	if(gold) destruct(gold);
	if(silver) destruct(silver);
	if(coin) destruct(coin);


	if( amount < 1 ) amount = 1;
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
	if( amount/100 ) {
		ob = new(SILVER_OB);
		ob->set_amount(amount/100);
		ob->move(who);
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int affordable(object me, int amount)
{
	int total;
	object cash, tencash, gold, silver, coin;

	tencash = present("tenthousand-cash_money", me);
	cash = present("thousand-cash_money", me);
	gold = present("gold_money",me);
	silver = present("silver_money",me);
	coin = present("coin_money",me);

	total = 0;
	if( tencash) total += tencash->value();
	if( cash) total += cash->value();
	if( gold ) total += gold->value();
	if( silver ) total += silver->value();
	if( coin ) total += coin->value();

	if( total < amount ) return 0;

	return total;
}
int do_redeem(string arg)
{
	int num;
	int amount;
	string ob_file;
	object ob;
	object me;
	int afford;
	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：redeem <物品标号>\n");
	me = this_player();
	amount = (int) me->query("vpawn/" + sprintf("%d", num));
	if( !amount )
		return notify_fail("阿珂问道：有这个物品标号吗？\n");
	amount = amount * 3 /4;
	if( afford = affordable(me, amount) )
	{
		pay_him(me, afford-amount);
		ob_file = me->query("fpawn/"+sprintf("%d",num));
		ob = new(ob_file);
		if(ob_file == "/clone/medicine/nostrum/guiyuandan.c" ||
			ob_file == "/clone/medicine/nostrum/huochan.c" ||
			ob_file == "/clone/medicine/nostrum/labazhou.c" ||
			ob_file == "/clone/medicine/nostrum/mangguzhuha.c" ||
			ob_file == "/clone/medicine/nostrum/renshenguo.c" ||
			ob_file == "/clone/medicine/nostrum/sanshi.c" ||
			ob_file == "/clone/medicine/nostrum/xuming8wan.c" ||
			ob_file == "/clone/medicine/nostrum/xiongdan.c" ||
			ob_file == "/clone/medicine/nostrum/zhujingchan.c" ||
			ob_file == "/clone/medicine/vegetable/fuxincao.c" ||
			ob_file == "/d/jianzhong/obj/shedan.c")
		{
			message_vision("$N典当的$n由于时间太久，变质化灰了。\n", me, ob);
			destruct(ob);
		}
		else
		{
			message_vision("$N从典当行赎回了$n。\n", me, ob);
			ob->move(me);
		}
		me->delete("pawn/"+sprintf("%d",num));
		me->delete("vpawn/"+sprintf("%d",num));
		me->delete("fpawn/"+sprintf("%d",num));
		me->save();
		return 1;
	} else return notify_fail("阿珂道：你的钱不够。\n");

}

