 //liwenxiu.c 李文秀

#include <ansi.h>

inherit NPC;
int ask_supu();
int ask_parent();
int ask_gaochang();
void dest(object ob);

void create()
{
	set_name("李文秀", ({ "li wenxiu", "li", "wenxiu" }));
	set("gender", "女性");
	set("age", 18);
	set("long", "她长得清纯脱秀，嫣然一笑，不禁让人怦然心动。\n");

	set("combat_exp", 100000);
	set("shen_type", 1);
	set("per", 28);
	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 10);
	set("map_count", 1);

	set_skill("force", 40);
	set_skill("sword", 100);
	set_skill("unarmed", 50);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	set("inquiry", ([
		"苏普" : (: ask_supu :),
		"supu" : (: ask_supu :),
		"父母" : (: ask_parent :),
		"parent" : (: ask_parent :),
		"高昌地图" : (: ask_gaochang:),
		"高昌迷宫" : (: ask_gaochang :),
		"map" : (: ask_gaochang:),
	]) );

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

int ask_supu()
{
	say("李文秀黯然的说：他是我儿时的伙伴，他现在和阿曼在一起了，\n");
	this_player()->set_temp("marks/李1", 1);
	return 1;
}

int ask_parent()
{
	object map;
	object me = this_player(); 
	if ((int)this_player()->query_temp("marks/李1"))
	{
		say("李文秀哽咽的说道：我的父母是被奸人害死的，奸人觊觎我们家的高昌地图。\n我一定要手刃仇人，为我父母报仇。\n");
		me->set_temp("marks/李2", 1);
		return 1;
	}
	else
	{
		say("李文秀说道：父母之仇，不共戴天。\n");
		return 1;
	}
}

int ask_gaochang()
{
	object map, me = this_player(), ob = this_object();
	int exp,pot,score;
	if (query("map_count") < 1)
	{
		say("李文秀一愣，忙道：地图？我没说过什么地图啊。\n");	
		return 1;
	}
	if ((int)me->query_temp("marks/李2"))
	{
//		say( "李文秀一惊，说道：你怎么知道的？噢，我刚才说露嘴了。\n那我就把地图送给你吧。你看看高昌迷宫到底有什么？\n");
//  	map=new("/d/gaochang/obj/map");
//		map->move(me);
//		add("map_count", -1);
		say( "李文秀一惊，说道：你怎么知道的？噢，我刚才说露嘴了。\n我把高昌地图给苏普了，你去找他吧。\n");
    me->set_temp("marks/李3",1);
	}
	else
	{
		message("vision", HIY"李文秀勃然大怒，喝道：你也窥视我父母的高昌地图？！我跟你拼了！\n"NOR, environment(), this_object() );
		ob->kill_ob(me);
		me->delete_temp("marks/李1");
		me->delete_temp("marks/李2");
	}
	return 1;
}
int accept_object(object me,object ob)
{
	object li=this_object();
	object map;
	int exp,pot,score;
	if (!me->query_temp("marks/李3"))
	{
		command("shake");
		command("say 计爷爷说不能别人的贪图财物。");
    return 0;
	}
  if (ob->query("id")=="shou juan"&& ob->query("blood_soaked")>=2)
  {
  	call_out("dest",0,ob);
  	if (!ob->query("owner") || ob->query("owner")!=me->query("id"))
  	{
  		message_vision("$N勃然大怒：你哪里偷来的这块手绢！\n",li);
  		me->fight_ob(li);
  		li->kill_ob(me);
  		return 1;
  	}
    message_vision("$N惊叫：这不正是高昌地图吗？\n",li);
    map=new(__DIR__"obj/map");
		map->move(me);
		ob=new(__DIR__"obj/shoujuan2");
		ob->move(me);
		li->add("map_count", -1);
	  if (!me->query("skybook/baima/map"))
  	{
  	 me->set("skybook/baima/map",1);
  	 exp=500+random(1000);
     pot=exp/2;
     score=pot/2;
     me->add("combat_exp",exp);
     me->add("potential",pot);
     me->add("score",score);
     	tell_object(me,HIC"你成功得到了高昌地图！\n在这次历练中你获得了"+
     	         chinese_number(exp)+"点经验、"+
               chinese_number(pot)+"点潜能以及"+
               chinese_number(score)+"点江湖阅历。\n\n"NOR);
  	}	
  	return 1;
  }
  return 0;
}
void dest(object ob)
{
	destruct(ob);
}