// npc: /d/city/npc/shenwanfu.c
// Last Modified by Sir 9/15/2001
//增加烫布任务

#include <ansi.h>
#include <command.h>

#define MAX_EXP 5000
#define MIN_EXP 1000
inherit NPC;
inherit F_DEALER;
int do_gongzuo();
void create()
{
	set_name( YEL "沈万福" NOR, ({ "shen wanfu","shen","wanfu" }) );
	set("gender", "男性" );
	set("title", "沈家白衣铺老板");
	set("age", 45);
	set("long", "沈万福是一个白胖子，脸上总是笑呵呵的，象一尊弥勒佛。看他的样子
不象是个买卖人，然而如果你仔细看看他那双眯缝的笑眼，就会发现里
面同样闪动着一丝狡黠的光芒。他就是这家白衣铺的老板。\n");
	set("chat_chance", 50);
	set("chat_msg", ({
		"沈万福道：这里就是扬州城啦，您家没有来过么？\n",
		"沈万福道：啊，这位客官，听您的口音是……北方……南方……西边……到底是哪儿的人啊？\n",
		"沈万福道：客官，咱这白衣，哎，没的说，您找不到比这更好的啦，来一件吧，啊？\n",
		"沈万福道：客官，您瞧瞧，这件白衣您穿上多精神哪！人靠衣服马靠鞍嘛，您说是不是这个理儿？\n",
	}));
	set("inquiry", ([
		"白衣" : "要买白衣，您到我这儿就找对地方了，绝对没错！\n",
		"here" : "吓，这儿可不就是扬州城嘛。\n",
		"工作" : (: do_gongzuo :),
		"job"  : (: do_gongzuo :),
		"work" : (: do_gongzuo :),
	]) );
	set("attitude", "friendly");
	set("vendor_goods", ({
		CLOTH_DIR+"cloth/baiduanshan",
		CLOTH_DIR+"cloth/baizhusipao",
		CLOTH_DIR+"cloth/commcloth",
		CLOTH_DIR+"cloth/hulannaao",
		CLOTH_DIR+"cloth/mabukuanshan",
		CLOTH_DIR+"cloth/shabuzhizhui",
		CLOTH_DIR+"cloth/zhifengkuanshan",
		CLOTH_DIR+"cloth/nenlvchoushan", 
		CLOTH_DIR+"cloth/danhuangshayi",
		CLOTH_DIR+"cloth/yinhongshanzi",
		CLOTH_DIR+"cloth/sahuaao",
	}) );

	set("attitude", "friendly");
	set("rank_info/respect", "老哥");
	set("rank_info/rude","老王八蛋");
	set("combat_exp",100);
	set_skill("unarmed", 5);
	setup();
	carry_object( "/clone/cloth/male-cloth")->wear();
}

int do_gongzuo()
{
	object me;	
	me = this_player(); 
	
	if (me->query("combat_exp")<MIN_EXP)
	{
		command("say 这里都是精细活，你现在还干不了。\n");
		return 1;
	}
	
	if (me->query("combat_exp")>=MAX_EXP)
	{
		command("say 这种小事不敢劳您大驾。\n");
		return 1;
	}
	if( me->query_temp("gongzuo/yunbu")>0)
	{
		tell_object(me,"快去把布匹熨好后交给我吧。\n");
		return 1;
	}
	message_vision(CYN"沈万福对$N说道：现在熨好的布匹不够用了，你就到后面的库房里去熨些布来。\n"NOR,me); 
	me->set_temp("gongzuo/yunbu", 1);
	return 1;
}
int accept_object(object me, object ob)
{
	object ob1;
	int add_exp,add_pot,add_score;
	if (strsrch(ob->query("name"), "熨好的布") < 0) 
	{
		command("say 你别来蒙我啦，这是熨好的布吗？\n");
	}
	else if (me->query_temp("gongzuo/yunbu")<1)
	{
		command("say 我没有叫你帮我熨布呀！\n");
	}
	else if (me->query_temp("gongzuo/yunbuok")<1)
	{
		command("say 这不是你熨的布呀！\n");
	}
	else
	{
		message_vision(CYN"沈万福对$N说道：辛苦了，这是你的工钱。\n"NOR,me);
		message_vision(CYN"沈万福递给$N一些银子。\n"NOR,me);

		me->delete_temp("gongzuo/yunbu");
		me->delete_temp("gongzuo/yunbuok");

		add_exp=30+random(20);
		add_pot=15+random(10);
		add_score=10+random(5);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_score);
		ob1->move(me);	
		tell_object(me,HIW"你得到了:"
			+ chinese_number(add_exp) + "点实战经验，"
			+ chinese_number(add_pot) + "点潜能，"
			+ chinese_number(add_score) + "点江湖阅历。\n"NOR);				
		call_out("destroying", 1, this_object(), ob);
		return 1;
	}
	return 0;
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

void init()
{
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision("沈老板笑呵呵的说道：“客官，您瞧瞧咱家的白衣怎么样？”\n",ob);
	return;
}
