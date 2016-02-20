//laoban.c 老板
#include <ansi.h>
inherit NPC;
string do_ask();
string do_tool();
string do_abort();
string do_finish();

void create()
{
	set_name("老板",({"lao ban","lao"}));
	set("long","他就是华山采石场的老板，一副很精明的样子，右手
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
	
	if (me->query_str()<18 || me->query("combat_exp")<5000)
	return ("“这位"+RANK_D->query_respect(me)+"也太瘦弱了吧，出了事我可负担不起。”\n");
	if (me->query_temp("caishi/count")>=1)
	return ("“这位"+RANK_D->query_respect(me)+"不是已经有工作了吗？不想做就放弃吧。”\n");
	titles=replace_string( me->query("title"), HIW" 采石工人"NOR, "");
	me->set("title",titles);
	me->add("title",HIW" 采石工人"NOR);
	me->set_temp("caishi/count",1);
	return("“好吧，这位"+RANK_D->query_respect(me)+"你就在这里好好干吧！”\n");
}

string do_tool()
{
	object me=this_player();
	object ob;
	if (present("hammer",me))
		return ("“这位"+RANK_D->query_respect(me)+"你身上已经有工具了。\n");
	ob=new("/clone/weapon/hammer");
	ob->move(me);
	message_vision("老板给$N一把铁锤。\n",me);
	return ("“这位"+RANK_D->query_respect(me)+"请把工具收好，别弄丢了。”\n");
}

string do_abort()
{
	object me=this_player();
	string titles;
	if (me->query_temp("caishi/count")<1)
		return ("“这位"+RANK_D->query_respect(me)+"还没工作就想放弃？来捣乱的吧。”\n");
	titles=replace_string( me->query("title"), HIW" 采石工人"NOR, "");
	me->delete_temp("caishi/count");
	me->delete_temp("caishi/finish");
	return("“其实这份工也很不错的，真是可惜！”\n");
}

string do_finish()
{
	object me=this_player();
	object ob;
	string titles;
//      if (!strsrch(me->query("title"),HIW"采石工人"NOR))
	if (me->query_temp("caishi/count")<1)
		return ("“这位"+RANK_D->query_respect(me)+"什么时候替我做过事啊？”\n");
	if (!me->query_temp("caishi/finish") )
		return ("“这位"+RANK_D->query_respect(me)+"做事要有恒心，不想做就趁早放弃!\n");
	else 
	{
		titles=replace_string(me->query("title"),HIW" 采石工人"NOR, "");
		me->delete_temp("caishi/count");
		me->delete_temp("caishi/finish");	       
//		me->add("potential",2+random(2));
//		me->add("combat_exp",5+random(7));
		me->delete_temp("caishi/finish");
		me->set("title",titles);
		ob=new("/clone/money/silver");
		ob->set_amount(10);
		ob->move(me);
		return("“嗯，这位"+RANK_D->query_respect(me)+"干得真是不错，这是你的工钱，请收好了。”\n");
	}
}
