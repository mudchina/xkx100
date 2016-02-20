//laoban.c 老板
#include <ansi.h>
#define MIN_EXP 20000
#define MAX_EXP 60000
inherit NPC;
string do_ask();
string do_tool();
string do_abort();
string do_finish();

void create()
{
	set_name("掌柜",({"zhang gui","boss"}));
	set("long","他就是华山采石场的掌柜，一副很精明的样子，右手
正拿着算盘，小眼睛眯缝着，透过老花镜打量着你。\n");
	set("gender","男性");
	set("title",CYN"采石场"NOR);
	set("age",50);
	set("inquiry",([
	      "工作" : (:do_ask:),
	      "采石" : (:do_ask:),
	      "work" : (:do_ask:),
	      "工具" : (:do_tool:),
	      "tool" : (:do_tool:),
	      "放弃" : (:do_abort:),
	      "abort" : (:do_abort:),
	      "交工" : (:do_finish:),
	      "finish" : (:do_finish:),
	]) );
	set("per",18);
	set("kar",22);
	
	set_skill("force",20);
	set_skill("dodge",20);
	set_skill("parry",20);
	set_skill("unarmed",20);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

string do_ask()
{
	object me=this_player();
	string titles;
	object room;
	object *inv;
	int i;
	
	if (me->query("combat_exp")>=MAX_EXP)
		return("大侠您就不要来和小辈们搅和了吧。");
	if (me->query_str()<18 || me->query("combat_exp")<MIN_EXP)
	return ("“这位"+RANK_D->query_respect(me)+"也太瘦弱了吧，出了事我可负担不起。”");
	if (me->query_temp("caishi/count")>=1)
	return ("“这位"+RANK_D->query_respect(me)+"不是已经有工作了吗？不想做就放弃吧。”");
	room = find_object("/d/huashan/caishi");
	if (!room) room = load_object("/d/huashan/caishi");
	inv = all_inventory(room);
	for (i=0;i<sizeof(inv);i++)
	{
		if (inv[i] != me 
		&& (query_ip_name(inv[i])==query_ip_name(me))
		&& inv[i]->query_temp("caishi/count"))
		return "你先歇会儿吧，这里已经有人帮忙了。";
	}
	titles=replace_string( me->query("title"), HIW"石匠"NOR, "");
	me->set("title",titles);
	me->add("title",HIW"石匠"NOR);
	me->set_temp("caishi/count",1);
	return("“好吧，这位"+RANK_D->query_respect(me)+"你就在这里好好干吧！”");
}

string do_tool()
{
	object me=this_player();
	object ob;
	if (present("hammer",me))
		return ("“这位"+RANK_D->query_respect(me)+"你身上已经有工具了。");
	ob=new(__DIR__"obj/hammer");
	ob->move(me);
	message_vision("老板给$N一把铁锤。\n",me);
	return ("“这位"+RANK_D->query_respect(me)+"请把工具收好，别弄丢了。”");
}

string do_abort()
{
	object me=this_player();
	string titles;
	if (me->query_temp("caishi/count")<1)
		return ("“这位"+RANK_D->query_respect(me)+"还没工作就想放弃？来捣乱的吧。”");
	titles=replace_string( me->query("title"), HIW"石匠"NOR, "");
	me->delete_temp("caishi/count");
	me->delete_temp("caishi/finish");
	return("“其实这份工也很不错的，真是可惜！”\n");
}

string do_finish()
{
	object me=this_player();
	object ob1;
	string titles;
	int add_exp,add_pot,add_score;
//      if (!strsrch(me->query("title"),HIW"石匠"NOR))
	if (me->query_temp("caishi/count")<1)
		return ("“这位"+RANK_D->query_respect(me)+"什么时候替我做过事啊？”");
	if (!me->query_temp("caishi/finish") )
		return ("“这位"+RANK_D->query_respect(me)+"做事要有恒心，不想做就趁早放弃!”");
	else 
	{
		titles=replace_string(me->query("title"),HIW"石匠"NOR, "");
		me->delete_temp("caishi/count");
		me->delete_temp("caishi/finish");	       
//		me->add("potential",2+random(2));
//		me->add("combat_exp",5+random(7));
		me->delete_temp("caishi/finish");
		me->set("title",titles);
		add_exp=60+random(20);
		add_pot=30+random(10);
		add_score=10+random(5);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_pot);
		ob1->move(me);	
		tell_object(me,HIW"你得到了:"
			+ chinese_number(add_exp) + "点实战经验，"
			+ chinese_number(add_pot) + "点潜能，"
			+ chinese_number(add_score) + "点江湖阅历。\n"NOR);
		return("“嗯，这位"+RANK_D->query_respect(me)+"干得真是不错，这是你的工钱，请收好了。”");
	}
}
