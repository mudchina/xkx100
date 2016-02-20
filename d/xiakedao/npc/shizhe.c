//NPC /npc/shizhe.c

inherit NPC;
#include <ansi.h>
#include <command.h>

void greeting(object);
void init();
int ask_for_xkd();

void create()
{
	set_name("黄衣使者", ( { "shi zhe", "zhe" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "这是个身着黄衣的三十几岁汉子，手持木浆，面无表情。\n");
	set("attitude", "friendly");
	set("no_get", 1);
	set("shen_type", 1);

	set("str", 30);
	set("int", 39);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 330);
	set("max_jing", 320);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 16000);
	set("score", 10000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);

	create_family("侠客岛", 2, "弟子");

	set("inquiry", ([
		"侠客岛" : (: ask_for_xkd :),
		"出海"   : "南边还有几艘船，你自己看看去吧！\n",
	]));
	setup();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	say("黄衣使者说道：这位" + RANK_D->query_respect(ob) + "你把我叫过来，有什么事吗。\n");
	return;
}

/*int accept_object(object who, object ob)
{
	object ling1;
	object ling2;
	object room, myenv;
 
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if ( (string)ob->query("id") != "shan pai"
		&& (string)ob->query("id") !="e pai" )
	{
		return notify_fail("我不需要这件东西。\n");
	}
	
	if ( query_temp("times")==0 )
	{
		return notify_fail("我太累了，不想出海。\n");
	}

	if ( !who->query("xkd/ling") )
	{
		tell_object( who, "黄衣使者说道：侠客岛只邀请成名武术家上岛，这位" + RANK_D->query_respect(who) + "还是请回吧。\n" );
		return 0;
	}
	
	if ( (string)ob->query("id") == "shan pai" )
	{
		if ( (string)ob->query("own") != (string)who->query("id") )
		{
			message_vision("这不是你的牌子。你这样欺骗我，不是想害我家破人亡吗？\n",who);
			return 0;
		}
		if (query_temp("ling")==2)
		{
			message_vision("使者一看是赏善铜牌，满脸歉意地对$N说：上岛的铜牌共两块，你还缺一块罚恶铜牌。\n",who);
			return 0;
		}
		add_temp("ling",2);
		if(!( room = find_object("/d/xiakedao/duchuan")) )
			room = load_object("/d/xiakedao/duchuan");
	
		room = find_object("/d/xiakedao/duchuan");
		room->add_temp("pai",2);
	
		if( query_temp("ling")==2 )
		{ 
			message_vision("使者一看是赏善铜牌，满脸欣喜地对$N说：你还有一块罚恶铜牌吗？\n",who);
			return 1;
		}
	}

	if ( (string)ob->query("id") == "e pai" )
	{
		if ( (string)ob->query("own") != (string)who->query("id") )
		{
			message_vision("这不是你的牌子。你这样欺骗我，不是想害我家破人亡吗？\n",who);
			return 0;
		}
		if(query_temp("ling")==1)
		{
			message_vision("使者一看是罚恶铜牌，满脸遗憾地对$N说：本岛铜牌一共两块，你还缺赏善铜牌。\n",who);
			return 0;
		}
		add_temp("ling",1);
		if(!( room = find_object("/d/xiakedao/duchuan")) )
			room = load_object("/d/xiakedao/duchuan");
		room = find_object("/d/xiakedao/duchuan");
		room->add_temp("pai",1);
	
		if( query_temp("ling")==1 )
		{
			message_vision("使者一看是罚恶铜牌，满脸欣喜地对$N说：你还有赏善铜牌吗？\n",who);
			destruct( ob );
			return 1;
		}
	}

	command("smile "+(string)who->query("id"));
	tell_object( who, HIG"原来是侠客岛的贵宾，这就随我上岛去吧。\n"NOR );
	ling1 = new("/d/xiakedao/obj/tongpai1");
	ling1->set_temp("own",who->query("id"));
	ling1->move(who);
	ling2 = new("/d/xiakedao/obj/tongpai2");
	ling2->set_temp("own",who->query("id"));
	ling2->move(who);
	set_temp("ling",0);
//	add_temp("times",-1);
	myenv = environment (who) ;
	who->move("/d/xiakedao/duchuan");
	tell_room(myenv, "黄衣使者招了招手，一只小舟靠岸，"+who->query("name")+"跨步上船。\n");
	call_out("goto_xiake",10,who) ;
	return 1;
}*/

int ask_for_xkd()
{
	object who = this_player();
	object ling1,ling2;
	object myenv;	
	object* inv;
	int i;
	
	if( !who || environment(who) != environment() ) return 0;
	
//	if ( !who->query("xkd/ling") || time() > who->query("xkd/time") )
	if ( !who->query("xkd/ling") )
	{
		message_vision("黄衣使者说道：小人在这活了一辈子，还从没听说过。\n", who );
		return 1;
	}
		/*
	if ( !objectp( ling1 = present( "shan pai", who ) ) ||
		!objectp( ling2 = present( "e pai", who ) ) )
	{
		message_vision( "黄衣使者说道：上侠客岛要有赏善罚恶令，这位" + RANK_D->query_respect(who) + "还是请回吧！\n", who );
		return 1;
	}
	
	if ( ling1->query("own") != who->query("id") ||
		ling2->query("own") != who->query("id") )
	{
		message_vision( "黄衣使者说道：" + RANK_D->query_respect(who) + "拿的不是自己的牌子。这样欺骗我，不是想害我家破人亡吗？\n", who );
		return 1;
	}
*/	
	inv = all_inventory(who);
	for(i=0; i<sizeof(inv); i++)
		if ( userp(inv[i]) )
		{
			message_vision( "黄衣使者说道：岛主颁下严令，只能迎接" + RANK_D->query_respect(who)+ "一人前往。\n若是多载一人，小舟固须倾覆，小人也是首级不保。\n", who );
			return 1;
		}
		
	command("smile "+(string)who->query("id"));
	tell_object( who, HIG"原来是侠客岛的贵宾，这就随我上岛去吧。\n"NOR );
	myenv = environment (who) ;	
	who->move("/d/xiakedao/duchuan");
	tell_room(myenv, "黄衣使者招了招手，一只小舟靠岸，"+who->query("name")+"跨步上船。\n");
	call_out("goto_xiake",10,who) ;	
	return 1;
}

void goto_xiake(object ob)
{
	tell_object(ob, HIB"你在海上航行了三天三夜，大船终于停在了一个小岛边。你走下船来。\n" ) ;
	ob->move ("/d/xiakedao/haitan") ;
}

