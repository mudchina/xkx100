// /d/xiakedao/npc/zhangsan.c 张三 赏善使者
// Modified by Zeratul Jan 11 2001 改为给猪腿换玄冰酒

inherit NPC;
int inquiry_jiu();
#include <ansi.h>
void create()
{
	set_name("张三", ({ "zhang san" , "zhang" ,"san" }) );
	set("nickname", HIR"赏善使者"NOR);
	set("gender", "男性" );
	set("age", 30);
	set("long", "只见他身材魁梧，圆脸大耳，穿一袭古铜色绸袍，笑嘻嘻地一脸和蔼可亲。\n");
	set("attitude", "friendly");
	set("shen_type", 1);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set_temp("野猪/forleg", 0);
	set("no_get",1);
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
	    "张三大声称赞着：好酒，真是好酒，真是尽兴！\n",
	    "张三咂咂嘴：可惜无肉下酒，不知有没有地方弄点肉来？\n",
	    "张三满脸堆笑地对你说道：你站在这干么呢？是不是想和兄弟我喝两杯？\n"

	}) );
	set("inquiry",([
		"酒" : (: inquiry_jiu :),
		"腊八粥":"\n去找龙岛主看看你的缘分吧。\n",
		"石破天":"\n他是我的结拜兄弟呀，他也在这呢。\n",
		"赏善罚恶令":"\n这是我们兄弟的信物。\n",
//		"here" : "这里当然就是侠客岛啦",
//		"侠客行" : "往南面走，进山后就明白了",
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
		message_vision("张三笑道：酒不是已经给你了吗？这位" + RANK_D->query_respect(me) + "不要开我们兄弟的玩笑。\n", me);
		return 1;
	}
	if( !me->query_temp("xkd/forleg") )
	{ 
		message_vision( "张三笑道：这位"+RANK_D->query_respect(me)+"，这不是酒。不是我小气，这东西你可喝不得的。\n", me);
		return 1;
	}
	if( !me->query_temp("xkd/backleg") )
	{ 
		message_vision("张三笑道：好，好。不过我还得和我的兄弟商量一下。\n",me);
		return 1;
	}	
	if( query_temp("野猪/forleg") || random(10) > 8 )
	{ 
		message_vision( "张三笑道：这位"+RANK_D->query_respect(me)+"来得不巧，酒我已经给了别人了。\n", me);
	}
	else
	{
		message_vision( "张三叹着气说：这位"+RANK_D->query_respect(me)+"，你为什么一定要喝这酒呢，这对你可未必有好处。\n好吧，既然你要，就给你吧，不过你要小心啊！\n",me);
//张三从腰间解下一个朱红色的葫芦，递了给你。\n" , me);
		obn = new( "/clone/medicine/nostrum/binghuojiu" );
		obn->move( me );
		me->set_temp( "xkd/jiu", 1);	
	}
	set_temp( "野猪/forleg", 1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me;
	me=this_object();
	command("smile");
	if( ob->query("money_id") )
	{
		command("say " + RANK_D->query_respect(who) +
			"多谢你的好意，我们哥俩不缺钱花。钱吗，我是要多少有多少。" );
		return 0;
	}
	if (ob->query("id")=="bone")
	{
		command(" say " + "你又何苦开这玩笑呢，这要被我兄弟李四看见了，他非杀了你不可。\n");
		return 1;
	}
	if( ob->query("id")=="for leg")
	{
//	    set_temp("野猪/forleg", 1);
		who->set_temp( "xkd/forleg" , 1 );
		return 1;
	}
	return 0;
}
