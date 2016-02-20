// lilishi.c 李力世

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int ask_weiwang();
int ask_zhu();
int ask_me();

mixed names = ({
({ "史青山", "林震南", "宋青书", "采花贼","独脚大盗","史松", }),
({ "狮吼子","飞天子","黯然子","温南扬","侯通海","沙通天", }),
({ "温方悟","温方施","史叔刚","武修文","钱青健","温方达","温方义","温方山","齐云敖","天狼子","包不同","风波恶","邓百川", }),
({ "殷天正","韦一笑","杨逍","范遥","慕容复","黛绮丝","潇湘子","李莫愁", }),
({ "张昭重","成昆","丁春秋","归辛树","归二娘","胡逸之","西华子", }),
});

void create()
{
	set_name("李力世", ({ "li lishi", "li" }));
	set("gender", "男性");
	set("age", 45);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一个高高瘦瘦的老者，满脸凄苦的神色，颔下一\n"
		"把稀稀拉拉的胡子，饱经沧桑的样子。身上的\n"
		"衣服又脏又破，脸上满是皱纹，看上去饱经风霜。\n");
	set("combat_exp", 35000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("claw", 50);
	set_skill("hand", 50);
	set_skill("blade", 50);
	set_skill("literate", 50);
	set_skill("wuhu-duanmendao", 50);
	set_skill("yunlong-shengong", 60);
	set_skill("yunlong-shenfa", 60);
	set_skill("yunlong-shou", 50);
	set_skill("yunlong-zhua", 50);
	map_skill("hand", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "wuhu-duanmendao");
	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");

	set("qi", 800);
	set("max_qi", 800);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 10);
	set("chat_chance", 2);
	set("chat_msg", ({
		"李力世说：呆会儿我还得把猪送到宫里去。\n",
		"李力世突然吆喝道: 花雕芙苓猪啊，只卖黄金一两，谁买谁买啊？\n",
		"李力世突然吆喝道: 燕窝人参猪啊，只卖黄金一两，谁买谁买啊？\n",
		"李力世搔了搔头，说道：这么好的猪肉怎么没人要啊。\n",
		"李力世突然说：初进洪门结义兄，对天明誓表真心。\n",
	}));
	set("inquiry", ([
		"陈近南" : "想见总舵主可不容易啊。\n",
		"天地会" : "只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"入会" : "只要入了我天地会，可以向会中各位好手学武艺。\n",
		"反清复明" : "去棺材店和回春堂仔细瞧瞧吧！\n",
		"暗号" : "敲三下！\n",
		"切口" : "敲三下！\n",
//		"反清复明" : (: ask_me :),
		"进宫" : (: ask_zhu :),
		"花雕芙苓猪" : (: ask_zhu :),
		"燕窝人参猪" : (: ask_zhu :),
		"威望" : (: ask_weiwang :),
		"江湖威望" : (: ask_weiwang :),
	]) );
	set("party/party_name", HIR"天地会"NOR);
	set("party/rank", HIG"青木堂"NOR"会众");
	create_family("云龙门", 2, "弟子");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
	carry_object(__DIR__"obj/tudao")->wield();
	add_money("silver", 20);
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say( "\n李力世说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
	say("李力世说：杀某些坏人或救某些好人可以提高江湖威望。\n");
	return 1;
}

int ask_zhu()
{
	if (this_player()->query_temp("money_paid"))
	{
		this_player()->delete_temp("money_paid");
		this_player()->set("huanggong\\canenter",1);
		say("李力世说：您老现在可以走啦！\n");
		return 1;
	}
	say("李力世说：干什么也得先交钱啊。\n");
	return 1;
} 

void init()
{
	::init();
	add_action("do_join","join");
}

int recognize_apprentice(object ob)
{
	if (ob->query("weiwang")<50)
	{
		message_vision("$N摇了摇头。\n",this_object());
		command("tell "+ob->query("id")+" 不是天地会弟子我不教。\n"); 
		return 0;
	}
	return 1;
}
/*
int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="li" )
		return 0;
	if(wizardp(ob)) return 0;
	if (ob->query("party/party_name") != HIR "天地会" NOR )
	{
		message_vision("$N摇了摇头。\n",this_object());
		command("tell "+ob->query("id")+" 不是天地会弟子不能察看。\n"); 
		return 1;
	}
	command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本刀法 (blade)			 - 一代宗师  90/    \n"+
"  基本轻功 (dodge)			 - 神乎其技  60/    \n"+
"  基本内功 (force)			 - 神乎其技  60/    \n"+
"  基本招架 (parry)			 - 出类拔萃  50/    \n"+
"  基本拳脚 (unarmed)		       - 出类拔萃  50/    \n"+
"□云龙身法 (yunlong-shenfa)		- 神乎其技  60/    \n"+ 
"□五虎断门刀 (wuhu-duanmendao)	     - 一代宗师  90/    \n");
	return 1;
}
*/
int ask_me()
{ 
	object ob, me;
	int exp,position;
	string target;
	me = this_player();
	ob = this_object();
	exp = me->query("combat_exp",1);
	if(me->query_condition("gb_mission") ||
		me->query_condition("guanfu_task") ||
		me->query_condition("xx_task") ||
		me->query_condition("xx_task") ||
		me->query_condition("xx_task2") ||
		me->query_condition("dali_songxin"))
	{
		command("say 你现在和江湖其他帮会纠葛不清，我不能交给你任务。");
		return 1;
	}
	if(me->query_condition("thd_task2") || me->query_condition("thd_task3"))
	{
		command("say 你正在执行天地会青木堂的任务！");
		return 1;
	}
/*	if (!me->query_temp("tdh_li") &&
		(me->query_condition("tdh_task_wait")<0))
	{
		command( "say 没有香主的命令，我不能交给你任务，天地会一向纪律严明。");
		return 1;
	}
	if (!me->query_temp("tdh_li"))
	{
		command( "say 没有香主的命令，我不能交给你任务，天地会一向纪律严明。");
		return 1;
	}
*/
 	if(exp>=850000) position=5;
	else if(exp>=600000) position=4;
	else if(exp>=300000) position=3;
	else if(exp>=150000) position=2;
	else position=1;
	target = names[position-1][random(sizeof(names[position-1]))];
	me->set_temp("tdh_target", target);
	me->apply_condition("tdh_task1",30); 
	me->clear_condition("tdh_task_wait");
	command( "say "+target+"最近投靠清廷，杀我会中兄弟，你去把此贼的人头提来，以祭亡灵！");
	if(!present("qingmu ling", me))
	{
		new(__DIR__"qml")->move(me);
		message_vision("李力世把一枚青木令交给了$N。\n", me);
		return 1;
	}
	return 1;
}
int accept_object(object who, object ob,object me)
{
/*
	if (!who->query("tdh_pass")) return 0;
	if (ob->query("id") != "head" ) return 0;
	if ( !who->query_temp("tdh_target")) return 0; 
*/
	if (ob->query("money_id") && ob->value() >= 10000) 
	{
		message_vision("\n李力世对$N一揖作礼，说道：这位客官，要什么尽管说。\n",this_player());
		who->set_temp("money_paid",1);
		return 1;
	}
	if (who->query_temp("tdh_target") && 
		(who->query_condition("tdh_task1")<0))
	{
		command("say 你来晚了，已经有人为会中兄弟报仇了。");
		return 0;
	}
	if ( ob->query("victim_name") != who->query_temp("tdh_target")+"的首级")
	{
		command( "say 天地会恩怨分明，怎能乱杀无辜呢？下次你要在违反会规我绝不客气！");
		return 0;
	}
	if ( ob->query("victim_user") )
	{
		command("say " + RANK_D->query_rude(who) + "，敢作弊！");
		return 0;
	}
	if ( ob->query("kill_by") != who)
	{
		command( "say 天地会全是顶天立地的豪杰，你怎麽冒领其他人的功劳呢？");
		return 0;
	}
	command("say 你能手刃恶贼，使会中兄弟大仇得报，好样的！");
	who->add("tdh_job",2);
	who->clear_condition("tdh_task1");
	who->delete_temp("tdh_target");
	who->deltet_temp("tdh_li");
	call_out("destroying", 1, ob);
	call_out("ok", 1, who);
	return 1;
} 

void destroying(object obj)
{
	destruct(obj);
	return;
}
#include "tiandihui.h";
