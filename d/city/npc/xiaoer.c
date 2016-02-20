// xiaoer.c

// inherit NPC;
inherit F_VENDOR_SALE;
#include <ansi.h>

void create()
{
//	reload("xiaoer");
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	setup();
}
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (wizardp(ob)) return;
	if (!ob->query_temp("welcome100") || ob->query("mud_age")<1000)
	{
		ob->set_temp("welcome100","1");
tell_object(ob,"\n\n店小二笑咪咪地说道：这位"+RANK_D->query_respect(ob)+"，欢迎来到"GRN"侠客行一百。"NOR"

    如果您有什么不明白的，可以问"RED"tell"NOR"老玩家。缺钱花，也可以请老
玩家帮您暂渡难关。大侠们都会乐于助人的。当然您也可以用"RED"help"NOR"来获
得我们给您的帮助。
    您在"HIR"help"NOR"中能看到很多帮助项目。
    这里的故事和情节，谜语的基本依据是金庸的十五本小说。如果您
对故事不太记得了或想了解多些可以用"RED"help intro"NOR"这个帮助项。如果您
从没玩过 MUD游戏，那就先看看"RED"help newbie"NOR"来新手上路吧。"RED"help cmds"NOR"
是这里所有玩家都能用的命令。想认识一下这里的地图就"RED"map map"NOR"，里
面有很多项目的，您可以选择地图项目"RED"map all"NOR"看到整个游戏的地图。
而在露天直接"RED"map "NOR"就是您现在呆的地方的地图。当然最重要的是向老玩
家请教，这就一定要会使用"RED"chat"NOR"这个命令啦。这里的帮助文件也因为我
们的工作而更新，多多留意哦。客店往西，南，南，东就到武馆了，叛
师在这里会吃亏的，所以没想好拜哪个门派就先去武馆学。扬州的武庙
是信息中心，常去看看那里的公告，最新的消息一定最早出现在那里。
    如果您对这个游戏的设计和管理有什么建议或意见，请不妨直接在
这"RED"mailto winder"NOR" 或者其他巫师，我们一定会认真考虑的。\n\n");
	}
	switch( random(2) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}
int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 5000) 
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
