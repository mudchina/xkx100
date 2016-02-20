// heersu.c
#include <ansi.h>
inherit NPC;
string ask_me();
string ask_he();

void create()
{
	set_name("赫尔苏", ({"heersu"}));
	set("gender", "男性");
	set("age", 65);
	set("long", "他是一个老参客，可是看起来却一贫如洗。据江湖传言，他藏有不少珍贵的人参首乌之类的宝货。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);

	set("inquiry",([
		"人参"   : (: ask_me :),
		"山参"   : (: ask_me :),
		"老山参" : (: ask_me :),
		"参"     : (: ask_me :),
		"何首乌" : (: ask_he :),
		"首乌"	 : (: ask_he :)
	]));
	set("item_count",1);
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}

string ask_me()
{
	object me = this_player();
	if ((int)(me->query("shen") < 0))
		return "你又来抢参啦，早被抢光了，没有了。\n";
	me->set_temp("heersu", "人参");
	return "那你就拿出钱来吧。\n";
}
string ask_he()
{
	object me = this_player();
	if((int)(me->query("shen") < 0))
		return "你又来抢首乌啦，早被抢光了，没有了。\n";
	me->set_temp("heersu", "首乌");
	return "那你就拿出钱来吧。\n";
}

int accept_object(object me, object ob)
{
	object obj;
	if ( !me->query_temp("heersu") )
	{
		message_vision("赫尔苏惶恐地对$N说：我不敢要您老的钱。\n", me);
		return 0 ;
	}
	if (ob->query("money_id") && ob->value() >= 50000)
	{
		if (me->query_temp("heersu") == "首乌")
		{
			if (query("item_count")>0)
			{
			message_vision("赫尔苏对$N说：好！既然这位"+RANK_D->query_respect(me)+"如此看得起我老头子，\n这棵首乌我留了很久了，就送给你吧！\n",me);
				me->delete_temp("heersu");
				obj = new("/clone/medicine/vegetable/heshouwu");
				obj -> move(me);
				add("item_count", -1);
			}
			else message_vision("赫尔苏对$N说：钱我先收着，有首乌时再说吧！\n", me);
		}
		else
		{
			if (query("item_count")>0)
			{
			message_vision("赫尔苏对$N说：好！既然这位"+RANK_D->query_respect(me)+"如此看得起我老头子，\n这棵参我留了很久了，就送给你吧！\n",me);
				me->delete_temp("heersu");
				obj = new("/clone/medicine/vegetable/renshen");
				obj -> move(me);
				add("item_count", -1);
			}
			else message_vision("赫尔苏对$N说：钱我先收着，我一定找个最大的老山参给您！\n", me);
		}
	}
	else message_vision("赫尔苏皱眉对$N说：您给的也太少了吧？\n", me);
	return 1;
}

