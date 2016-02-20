// /kungfu/class/taohua/rong.c 黄蓉

#include <ansi.h>
#include "game.h"

inherit NPC;
inherit F_MASTER;

string ask_chicken();
int ask_jiuyin();
int ask_game();

void create()
{
	set_name("黄蓉", ({"huang rong", "huang", "rong"}));
	set("gender", "女性");
	set("age", 18);
	set("long", "这是桃花岛主的独生女儿。由于岛主夫人早死，岛主对这个女儿备加疼爱。她生性跳脱飞扬，喜欢四处乱跑。\n");

	set("attitude", "peaceful");
	set("class", "scholar");
	set("per", 30);
	set("str", 18);
	set("int", 30);
	set("con", 21);
	set("dex", 26);

	set("qi", 1800);
	set("max_qi", 1800);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 0);
	
	set("combat_exp", 200000);
	set("score", 0);
	set("jiacount", 1);
	set("env/wimpy", 60);
	
	set_skill("force", 60);
	set_skill("bibo-shengong", 80);
	set_skill("unarmed", 80);
	set_skill("xuanfeng-leg", 80);	  // 旋风扫叶腿
	set_skill("strike", 80);			// 基本掌法
	set_skill("luoying-zhang", 80);
	set_skill("dodge", 150);
	set_skill("anying-fuxiang", 100);
	set_skill("parry", 85);
	set_skill("literate",150);		   // 读书识字
	set_skill("sword", 80);
	set_skill("luoying-shenjian",80);
	
	map_skill("force"  , "bibo-shengong");
	map_skill("unarmed", "xuanfeng-leg");
	map_skill("strike" , "luoying-zhang");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("sword"  , "luoying-shenjian");
	
	create_family("桃花岛", 2, "弟子");

	set("inquiry", ([
		"黄药师" : "爹爹呀, 不在厅里麽? ",
		"郭靖"   : "怎么? 你有我靖哥哥的消息吗? ",
		"洪七公" : "师父他老人家就喜欢吃叫化鸡! ",
		"叫化鸡" : (: ask_chicken :),
		"九阴真经经义" : (: ask_jiuyin :),
		"游戏"   : (: ask_game :),
	]) );

	setup();
	carry_object(__DIR__"obj/ruanwei")->wear();
	carry_object(__DIR__"obj/shudai")->wear();
}

init()
{
	object ob;
	mapping myfam;
		
	::init();
	add_action("do_kiss", "kiss");
	if (interactive(ob = this_player()) && !is_fighting())
	{
		myfam = (mapping)ob->query("family");
		if ((!myfam || myfam["family_name"] != "桃花岛") &&
			(!wizardp(ob)))
		{
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
	}
}
int do_kiss ( string arg )
{
	object ob = this_player () ;
	if( !arg || arg!="rong" ) return 0;
   
	if ( (string) ob -> query ("gender") == "男性" )
		command("say 来人！救命啊！"+ob->query("name")+"要非礼我！\n");
	else
		message_vision("\n黄蓉对$N笑道：“好姐姐不要这样，我怕痒！”\n", ob);
	return 1 ;
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	if ((string)ob->query("gender") == "男性")
		message_vision("\n黄蓉面现惊奇之色，打量了$N一眼，说到：“你是什么人，竟敢乱闯我的闺房？\n再不滚出去，看我怎么整你！”\n", ob);
	else
		message_vision("\n黄蓉看了看$N，说到：“好久没生人来过了，不知这位姐姐可有我靖哥哥的消息？\n", ob);
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_temp("marks/蓉儿")==1)
	{
		say( "黄蓉一脸笑意：“多谢你带来靖哥哥的口信！”\n");
		if (query("jiacount")== 1)
		{
			say( "黄蓉轻轻一笑：我不收徒的..可也不能让你白来，这软猥甲就送给你吧。\n");
			new("/kungfu/class/taohua/obj/ruanwei")->move(ob);
			tell_object(ob,"黄蓉从身上脱下一件软猥甲递给你。\n");
			ob->set_temp("marks/蓉儿",2);
			set("jiacount", 0);
		}
	}
	else
		command("say 我年纪这么小就收徒弟，岂不让人笑掉大牙！");
}

string ask_chicken()
{
	if (this_player()->query_temp("marks/鸡", 1))
		return "你这个人怎么这么烦？老说车轱辘话！\n";
	else
	{
		say("蓉儿神往地说：叫化鸡可是杭州著名特产，我爹当年费了好大的劲才搞到了制作\n"
			"它的秘方。你问它来干什么？\n");
		this_player()->set_temp("marks/鸡", 1);
		return "你可以出去了。\n";
	}
}

int ask_jiuyin()
{
	object me = this_player();
	
	if(me->query("family/family_name")=="白驼山派" && !me->query("reserve")
		&& me->query("family/master_id") == "ouyang feng" )
	{
		if(me->query("combat_exp")>500000 && present("mask_jiuyin",me))
		{
			destruct( present("mask_jiuyin", me) );
			message_vision(HIY "黄蓉眼中闪过一丝狡黠的神色：“你想知道真经的解释么？好吧，我说给你听便是。”\n", me);
			message_vision("说罢，接过$N手中的经书，轻轻念了起来：\n", me);
			message_vision("“「忽不尔，肯星多得，斯根六补」这是「善用观相，运作十二种息」的意思。\n", me);
			message_vision("「吉尔文花思，哈虎」嗯....这个该作「能愈诸患，渐入神通」解...”\n", me);
			message_vision(HIG "$N大为兴奋，忙凝神倾听，内息早于不知不觉中按照黄蓉所解之法四处游走......\n", me);
			message_vision("$N的神智渐渐迷糊起来，忽而抓耳挠腮，忽而侧头苦思，种种怪状，令人不解。\n", me);
			message_vision("突然间，$N反手啪啪啪连打自己三个耳光，双手撑地，倒立了起来，全身真气逆游乱走 \n"NOR, me);
			if (random(5) == 3)
			{
				tell_object(me,"过了半晌，你只觉得全身经脉运行方式大为异常，略一提气，发现阴维，阳维，阴峤， \n");
				tell_object(me,"阳峤四脉颇有逆行之势，不由得又惊又喜。\n");
				me->set("reserve", 1);
				me->add("eff_jing", -100);
				me->add("max_neili", -2);
			} else {
				tell_object(me,"过了半晌，你心中一团乱麻，浑身乏力，头痛欲裂。一声嘶吼，晕了过去...\n");
				me->add("eff_jing", -100);
				me->add("max_neili", -2);
				me->unconcious();
			}
			return 1;
		} else  return notify_fail("黄蓉白了你一眼：“就你这点微末道行，想学九阴真经？也不怕被人笑掉大牙么？”\n");
	} else return 0;
}

int ask_game()
{
	object me = this_player();
	object ob = this_object();

	if (me->query_temp("match_game/playing")) {
		write("你已经在玩游戏了。\n");
		return 1;
	}
/*	if (me->query_temp("match_game/lost")) {
		message_vision( "$n仰起头不屑的对$N说道：你太笨了，我才不跟你玩呢。\n", me, ob );
		return 1;
	}*/
	if (me->query_temp("match_game/win")) {
		message_vision( "$n点了点头道：好吧！上次侥幸让你赢了，这回你就没这么好运气了。\n", me, ob );
		me->delete_temp("match_game/win");
	}
	else
		message_vision( "$n眉头一扬，对$N说到：好啊，看看你到底有多聪明。\n", me, ob );
	return play_game(me,ob);
}
