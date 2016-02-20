// letter.c
// Last Modified by sir
// 做成3万exp经验以下的新手入门任务,增加exp ,pot奖励,恢复silver奖励

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"信件"NOR, ({ "letter","xin","secret letter" }));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "封");
		set("long",
			"这是一封信件，信封的很严实，封口盖着红漆印戳。\n");
		set("value", 0);
		set("material", "paper");
		set("no_drop",1);
		set("no_give",1);
		set("no_put",1);
	}
}
void init()
{	
	call_out("dest",random(200)+1200);
	add_action("do_send", "songxin");
	add_action("do_look", "kan");
	add_action("do_look", "chakan");
//	add_action("do_getxin", "get");
}
/*
int do_getxin(string arg)
{
	object me;
	me = this_player();
	
	if( (arg=="letter"||arg=="xin"||arg=="all")&&!me->query_temp("gb_songxin")) 
		return notify_fail("你不能拿别人的东西。\n");
}
*/
int do_look(string arg)
{
	int now_time, time;
	object me;

	me = this_player();
	now_time = me->query_condition("gb_songxin"); 
	time = me->query_temp("songxin_time");

	if(!arg) return 0;
	if( (arg=="letter"||arg=="xin")&&me->query_temp("gb_songxin"))
	{
		write("\n这是一封由丐帮九袋长老鲁有脚发出的信件，上面写着"
			HIR" 「"+me->query_temp("songxin_target_name")+"」 亲启。\n"NOR);
		if(now_time > time*3/4) write("你现在有充足的时间去送信。\n");
		if(now_time > time/2 && now_time <= time*3/4)
			write("已经过去一小半时间了。\n");
		if(now_time > time/4 && now_time <= time/2)
			write("你还有一半的时间去送信。\n");
		if(now_time > time/8 && now_time <= time/4)
			write("你的时间已经不多了。\n");
		if(now_time > 0 && now_time <= time/8)
			write("时间将至，任务即将失败。\n");
	}
	else
	{
		if( (arg=="letter"||arg=="xin")&&!me->query_temp("gb_songxin")) 
			write("这是一封密函，信封的很严实，封口盖着红漆印戳。\n");
	}
	return 1;
}

int do_send(string arg)
{
	int i,exp,pot,score,num,s_bonus,times,job_time,paytimes;
	object ob;
	object me,target,payment;
	string t_name;
	mapping fam;

        paytimes = 0;
	me=this_player();
	if(!arg) return notify_fail("你要送给谁？\n");
	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("看清楚点，你要送信的人不在这里！\n");
	t_name = target->query("name");
	job_time = me->query_temp("songxin_time");
	i = random((int)(target->query_skill("force",1)/5));

       	if(!target) return notify_fail("看清楚点，你要送信的人不在这里！\n");
	if(userp(target)) return notify_fail("嘿嘿，想作弊？！\n");
	if(me->query_temp("gb_songxin_late"))
		return notify_fail("你任务已经失败了，重新再领一个吧。\n");
	if (!present("secret letter", this_player()) )
		return notify_fail("你身上没有携带信件。\n"); 
/*
	if (!(fam = me->query("family")) || fam["family_name"] != "丐帮")
		return notify_fail(RANK_D->query_respect(me) + "与丐帮素无来往，怎么会送信给我？");
*/
	if (!me->query_temp("gb_songxin"))
		return notify_fail(t_name+"道：这是丐帮亲自交给你，要你送的？你是不是从别人那里抢来的？");
	if(me->query_temp("songxin_target_name") != t_name) 
		return notify_fail(t_name+"道：这封信不是给我的，你是不是送错了？");

	message_vision(HIY"$N擦了一把额头的汗，从怀中掏出信交给$n说道，这是丐帮鲁长老让在下送给您的信，请您收好。\n"NOR, me, target);
	message_vision("$N交给了$n一封信。\n",me, target);
	message_vision(t_name+"点了点头说道：辛苦你了,这辛苦费你就收下吧! \n",me);
	target->add_money("silver",(int)(target->query_skill("force",1)/5)+1);
	command("give "+me->query("id")+" "+((int)(target->query_skill("force",1)/5)+1)+" silver");

	message_vision(HIY "$N接过信看了看，点了点头说道：这位"+RANK_D->query_respect(me)+"辛苦你了。\n"NOR, target, me);
 

	if ((int)me->query("combat_exp")<=5000)
	{
		if (!me->query_temp("zuji"))
		{
			exp=((1+random(3))*50+(int)(job_time/5));
			pot=30+random(20);
		}
		else
		{
			exp=((1+random(3))*90+(int)(job_time/5));
			pot=50+random(20);
		}
	}
	if ((int)me->query("combat_exp")<=20000
		&&(int)me->query("combat_exp")>5000)
	{
		if (!me->query_temp("zuji"))
		{
			exp=(1+random(2))*70+(int)(job_time/6);
			pot=40+random(15);
		}
		else
		{
			exp=(1+random(2))*100+(int)(job_time/6);
			pot=60+random(30);
//			if (pot >150) pot=150;
		}
	}
	if ((int)me->query("combat_exp")>20000)
	{
		if (!me->query_temp("zuji"))
		{
			exp=(1+random(2))*60+(int)(job_time/8);
			pot=30+random(30);
		}
		else
         	{
			exp=(1+random(2))*80+(int)(job_time/16);
			pot=40+random(40);
//			if (pot >180) pot=180;
		}
	}

        
        num=(int)me->query("perform/number")+1;
        if (num<4) times=num;
         else times=4;
        
        if (!(fam = me->query("family")) || fam["family_name"] != "丐帮")  score = 0;
         else score=random(10)+ 10 * times;
	
	s_bonus=50+random(50);
	
	me->add("potential",pot);
	me->add("combat_exp",exp);
	me->add("score",s_bonus);
        me->add("family/fealty",score);
	me->add("gb_job",1);
/*
        if (paytimes<i)       
        {
            payment=new("/clone/money/silver");
            payment->move(me);
            me->add("paytimes",1);
        }
*/
//      silver奖励

	tell_object(me,HIW"好！任务完成,你被奖励了：\n" + 
		chinese_number(exp) + "点实战经验\n" +
		chinese_number(pot) + "点潜能\n"+
		chinese_number(score) + "点忠诚度\n"+
		chinese_number(s_bonus) + "点江湖阅历\n" +
		chinese_number(i)+"两白银\n"+
		"你为丐帮做了"+me->query("gb_job")+"次工作。\n"NOR);
		me->apply_condition("gb_songxin", me->query_condition("gb_songxin")/2);
		me->delete_temp("gb_songxin");
		me->delete_temp("songxin_time");
		me->delete_temp("songxin_target_name"); 
		me->delete_temp("songxin_where");
		me->delete_temp("letter_steal"); 
		me->delete_temp("zuji");
		me->set_temp("songxin_ok",1);
		me->delete_temp("songxin_zuji");
	      //me->clear_condition("gb_songxin");
		destruct(this_object());
		return 1;
}

void dest()
{
		destruct(this_object());
}
