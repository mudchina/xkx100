// /d/xiakedao/npc/lisi.c 李四，罚恶使者
// Modified by Zeratul Jan 11 2001 改为给猪腿换玄冰酒

inherit NPC;
#include <ansi.h>
int inquiry_jiu();

void create()
{
	set_name("李四", ({ "li si" , "li" , "si" }) );
	set("nickname", BLU"罚恶使者"NOR);
	set("gender", "男性" );
	set("age", 30);
	set("long", "只见他身材甚高，十分瘦削，身穿天蓝色长袍，一脸的苦象。\n");
	set("attitude", "friendly");
	set("shen_type", 0);

	set_temp("野猪/forleg", 0);
	set("no_get",1);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 2000000);
	set("score", 20000);
	set_skill("parry", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("taixuan-gong", 200);
	map_skill("parry", "taixuan-gong");
	map_skill("force", "taixuan-gong");
	map_skill("dodge", "taixuan-gong");
	map_skill("unarmed", "taixuan-gong");
	set("chat_chance",3);
	set("chat_msg",({
	    "李四大声称赞着：好酒，真是好酒，真是酒逢知己千杯少啊！\n",
	    "李四咂咂嘴：可惜无肉下酒，喝起来不爽。\n",
	    "李四斜睨着你说道：你站在这干么呢？难道也想和我兄弟俩干一杯不成？\n"
	}) );
	set("inquiry",([
	   "酒"     : (: inquiry_jiu :),
//	   "here"   : "这里当然就是侠客岛啦。",
//	   "侠客行" : "往南面走，进山后就明白了。",
	]) );
	create_family("侠客岛", 2, "弟子");
	setup();
}

int inquiry_jiu()
{
	object me=this_player();
	object obn;

	if ( me->query_temp( "xkd/jiu" ) )
	{ 
		message_vision("李四瞪眼说到：酒不是已经给你了吗？这位"+RANK_D->query_respect(me) + "不要贪得无厌。\n", me);
		return 1;
	}
	if( !me->query_temp("xkd/backleg") )
	{ 
		message_vision( "李四瞪眼说到：这位"+RANK_D->query_respect(me)+"，你以为这是什么酒，是二锅头啊？？这么宝贵的东西我怎能随便给人呢。\n", me);
		return 1;
	}
	if( !me->query_temp("xkd/forleg") )
	{ 
		message_vision( "李四瞪眼说到：这位"+RANK_D->query_respect(me)+"，想要酒我还得和我的兄弟商量一下。\n", me);
		return 1;
	}	
	if( query_temp("野猪/backleg") || random(10) > 5 ) 
	{ 
		message_vision( "李四瞪眼说到：这位"+RANK_D->query_respect(me)+"来得不巧，酒我已经给了别人了。\n", me);
	}
	else
	{
		message_vision( "李四冷冷地说道：这位" + RANK_D->query_respect(me)+"，居然想喝我的毒酒，好吧，你有胆子就喝吧，不过可别后悔。\n",me);
		obn = new( "/clone/medicine/nostrum/binghuojiu" );
		obn->move( me );
		me->set_temp( "xkd/jiu", 1 );
	}
	set_temp( "野猪/backleg", 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object me;
	me=this_object();
	if( ob->query("money_id")  )
	{
		command("say " + RANK_D->query_respect(who) +
		"你以为我们哥俩缺钱花吗？告诉你吧，你就算把皇宫大内" +
		"的奇轸异宝都摆到我面前，我也视如粪土。" );
		return 0;
	}
	if (ob->query("id")=="bone")
	{
	       command(" say " + "你这厮，居然敢拿这种东西来戏弄老子。真是天堂有路你不走，地狱无门你偏来。\n");
	       me->set_leader(who);
	       me->kill_ob(who);
	       who->fight_ob(me);
	       return 0;
	}
	if( ob->query("id")=="back leg")
	{
	       who->set_temp("xkd/backleg", 1);
	       return 1;
	}
	return 0;

}
