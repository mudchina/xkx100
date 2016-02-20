// /cmds/skill/learn.c

// Modified by Constant Jan 11 2001

inherit F_CLEAN_UP;

#include <skill.h>
#include <ansi.h>


string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, teacher, master, skill_name;
	object ob;
	int master_skill, my_skill, jing_cost, times, pertimes;
	int improve_points;
	 mixed flag;
	 int i;
	 
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	if (environment(me)->is_chat_room())
	  return notify_fail("这里禁止练功。\n");
	if(!arg || (sscanf(arg, "%s %s %d", teacher, skill, times)!=3 ))
		return notify_fail("指令格式：learn|xue <某人> <技能> <次数>\n");
	if (times < 1 || times > 100)
		return notify_fail("学习次数最少一次，最多也不能超过一百次。\n");
	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");
	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");
	if( !living(ob) || ob->query_temp("noliving") )
		return notify_fail("嗯....你得先把"+ob->name()+"弄醒再说。\n");

  notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
	if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me,skill)) )
	{
		return	0;	
	}
	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

	if (stringp(flag = ob->query("no_teach/" + skill)))
	{
		message_vision(CYN "$N" CYN "摇摇头，说道：" + flag + "\n" NOR, ob);
		return 1;
	} else
	if (intp(flag) && flag)
	{
		if (flag != 1)
			// show the messaeg if the result was not -1
			write(CYN + ob->name() + CYN "说道：对不起，" +
				to_chinese(skill) + "可不能随便传授。\n" NOR);
					return 1;
	}

  notify_fail(ob->name() + "不愿意教你这项技能。\n");
	if( ob->prevent_learn(me, skill) )
		return 0;
	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("这项技能你的程度已经不输你师父了。\n");
	if( my_skill >= (int)(master_skill - me->query("betrayer")*2))
		return notify_fail(ob->name() +"皱了皱眉头，不禁想起你过去的叛师经历。\n");
	if ( userp(ob) && my_skill >= 200 )
		return notify_fail("依你目前的能力，已不需向玩家学习了。\n");
	if ((SKILL_D(skill)->type())!="knowledge" && my_skill >= 250)
	  return notify_fail(ob->name() + "说道：你" + to_chinese(skill) +"的功力已经是非同凡响了，我就不再教你，你自己多研究吧。\n");
	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
	if( !SKILL_D(skill)->valid_learn(me) ) 
	return 0;

	jing_cost = 150 / (int)me->query("int");
	if( !my_skill )
	{
		jing_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (me->query("potential") - me->query("learned_points")) < times )
		return notify_fail("你的潜能不够学习这么多次了。\n");
	printf(HIC"你向%s请教了"+chinese_number(times)+"句有关「%s」的疑问。\n"NOR, ob->name(), to_chinese(skill));
	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");
	tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
		me->name(), to_chinese(skill)));
	if (userp(ob))
	if(  (int)ob->query("jing") > jing_cost*times/5 + 1 )
	{
		  ob->receive_damage("jing", jing_cost/5 + 1);
	}
	else
	{
		write("但是" + ob->name() + "显然太累了，没有办法教你什么。\n");
		tell_object(ob, "但是你太累了，没有办法教"+me->name()+"。\n");
		return 1;
	}
		if( (string)SKILL_D(skill)->type()=="martial" &&
		my_skill*my_skill*my_skill/10 > (int)me->query("combat_exp") )
		{
			return notify_fail("也许是缺乏实战经验，你对"+ob->name()+"的回答总是无法领会。\n");
		}
    if (!me->query("env/auto_regenerate") && 
        				me->query("jing")< jing_cost * times)
							return notify_fail("你今天太累了，结果什么也没有学到。\n");
//	if( (int)me->query("jing") > jing_cost * times )
			for (pertimes = 0; pertimes < times ; pertimes ++)
			{
				if ((int)me->query("jing") < jing_cost)
        {
            if (me->query("env/auto_regenerate") &&
                SKILL_D("force/regenerate")->exert(me, me))
              {
              // try to regenerate & learn again
               write("你觉得精神好了一些，继续进行学习。\n");
               pertimes--;
                continue;
            } else
              {
//             me->set("jing", 0);
             break;
              }
        }
 				me->receive_damage("jing", jing_cost );    
				me->add("learned_points", 1);

			}
			if (pertimes>0)
			{
				for (i=0;i<pertimes;i++)
				{
// 学习速度 = 后天悟性加上先天悟性的和的一半，加武功学习补偿。
// 未定义学习补偿的技能，默认学习补偿为10。
					improve_points = (me->query_int()+me->query("int"))/2;
					if(SKILL_D(skill)->learn_bonus())
						improve_points += SKILL_D(skill)->learn_bonus();
					else improve_points += 10;
// 调整向师父学习技能的速度，加重对叛师的惩罚。
					improve_points = improve_points / (me->query("betrayer") + 1);
					if (improve_points < 15) improve_points = 15;
					improve_points = random(improve_points);
// 对师傅传授产生误解的比率。== 0时候误解。
//				if(random(SKILL_D(skill)->success()) )
						me->improve_skill(skill, improve_points);
				}
				if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
	 				printf("你听了%s的指导，对「%s」这一招似乎有些心得。\n", ob->name(), skill_name);
				else
					printf("你听了%s的指导，似乎有些心得。\n", ob->name());
        if (pertimes < times)
         return notify_fail("但是你今天太累了，学习了" + chinese_number(pertimes) +"次以后只好先停下来。\n");
			}
			else
				return notify_fail("你今天太累了，结果什么也没有学到。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : learn|xue <某人> <技能> <次数>

    这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你
请教的对象在这项技能上的造诣必须比你高，而你经由这种方式学习得来
的技能也不可能高于你所请教的人，然而因为这种学习方式相当於一种「
经验的传承」，因此学习可以说是熟悉一种新技能最快的方法。

    通常，一个人刚学到一种新技能是不会有什么疑难问题的，而是经由
实际上的应用中遭遇问题，这些问题对於学习一种新技能的过程是很重要
的，尤其是各种作为其他技能基础的基本技能，更需要经由「发现问题—
解决问题」的过程才能得到较好的效果因此我们将这种发现问题的过程用
「潜能」的观念表示，一个人能够自己发现某些问题，表示他（她）有解
决这项问题的潜能，当你具有这样的潜能时就可以利用这个指令来向其他
人请教，而获得进步。

(PS. 潜能还有其他更广义的定义，这里只是其中之一 )

    此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对
象的悟性有关。

    至于如何知道你能从对方学到什么技能，如果对方是你的师父，可以
用 skills 指令直接查看，如果不是你的师父，那么通常会有其他的提示，
你只好自己想办法。

其他相关指令 : apprentice, practice, skills, study
HELP
	);
	return 1;
}

