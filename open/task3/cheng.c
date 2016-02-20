// cheng.c
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int ask_me();
int ask_stop();

void create()
{
	set_name("程药发", ({ "cheng yaofa", "cheng" , "yaofa"}) );
	set("title", "扬州知府" );
	set("gender", "男性" );
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("long", "他就是程药发，扬州现任知府。\n");
	set("combat_exp", 30000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);
	set("inquiry", ([
		"任务": (: ask_me :),
		"捕快": (: ask_me :),
		"work": (: ask_me :),
		"效力": (: ask_me :),
		"quest": (: ask_me :),
		"扬州府": (: ask_me :),
		"放弃": (: ask_stop :),
		"stop": (: ask_stop :),
	]) );
	setup();
	carry_object(__DIR__"obj/mangpao")->wear();
	carry_object(__DIR__"obj/zizhuxiao")->wield();
	add_money("silver",30);
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_answer", "answer");
}
int ask_me()
{
	object ob,me;
	me = this_player();
	if(me->query("officerlvl") < 1)
	{
		command("say 这位"+ RANK_D->query_respect(me)
			+ "若有意为朝廷效力，不妨到签押房报名！\n");
		return 1;
	}
	command("say 你身为朝廷官员，不能白吃国家俸禄，须得努力工作(work)才是
啊！每次办差归来须如实向本府汇报(finish)。");
	return 1;
}
int ask_stop()
{
	object ob,me;
	me = this_player();
	if (!(int)me->query_temp("bt/working"))
	{
		command("say 这位"+ RANK_D->query_respect(me)
			+ "若不愿意为朝廷效力，本府也不勉强！\n");
		return 1;
	}
	command("say 你真的没有抓到罪犯吗？(answer yes或answer no)");
	me->set_temp("bt/stop",1);
	return 1;
}
int do_answer(string arg)
{
	object ob,me;
	me = this_player();
	if (!me->query_temp("bt/stop"))
	     return notify_fail("什么？\n");
	if (!arg || (arg !="yes"&&arg !="no"))
	{
		command("say 你吞吞吐吐的在说什么啊！\n");
		return 1;
	}
	if (arg =="no")
	{			       //113
		command("say 罪犯既已抓到了你还要放弃什么？\n");
		return 1;
	}
	message_vision (BLU"程药发不由大怒，拍案而起。\n"NOR,me);
	command("say 大胆！汝身为朝廷官员，食国家俸禄，办差如此不力，休怪本府无情！");
	command("say 来啊，与我重责二十大板。");
	message_vision (BLU"四下里顿时拥出几个如狼似虎的衙役将"+me->query("name")+"按翻在地。\n"NOR,me);
	me->delete_temp("bt/stop");
	me->apply_condition("bt_stop", 10);
	return 1;
}

