// /cmds/skill/research.c

// Modified by Constant Jan 11 2001

inherit F_CLEAN_UP;

#include <skill.h>
#include <ansi.h>


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, skill_name;
	object where = environment(me);
	int my_skill, jing_cost, times, pertimes;
	int improve_points;
	int i;

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if (!where->query("sleep_room"))
		return notify_fail("这里太纷杂，你没法做研究。\n");

	if(!arg || (sscanf(arg, "%s %d", skill, times)!=2 ))
		return notify_fail("指令格式：research|yanjiu <技能> <次数>\n");

	if (times < 1 || times > 100)
		return notify_fail("研究次数最少一次，最多也不能超过一百次。\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕没法研究了。\n");

	if( (string)SKILL_D(skill)->type()=="knowledge")
		return notify_fail(to_chinese(skill)+"只能靠你学习才能提高的。\n");

	notify_fail("依你目前的能力，没有办法研究这种技能。\n");
	if(!SCBORN_D->valid_learn(me,skill) && !SKILL_D(skill)->valid_learn(me) && my_skill < 200) return 0;

	jing_cost = 300 / (int)me->query("int");
	if( !my_skill ) {
		jing_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (me->query("potential") - me->query("learned_points")) < times )
		return notify_fail("你的潜能不够研究这么多次了。\n");
	printf(HIM"你研究了"+chinese_number(times)+"次有关「%s」的疑问。\n"NOR, to_chinese(skill));

	my_skill = me->query_skill(skill, 1);

	if( (string)SKILL_D(skill)->type()=="martial"
	&& my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
	{
		return notify_fail("也许是缺乏实战经验，你没法研究"+to_chinese(skill)+"的问题了。\n");
	} else
	{
    if (!me->query("env/auto_regenerate") && 
        				me->query("jing")< jing_cost * times)
		return notify_fail("你今天太累了，结果什么也没有研究成。\n");			
		for (pertimes = 0; pertimes < times ; pertimes ++)
		{
			if ((int)me->query("jing") < jing_cost)
      {
         if (me->query("env/auto_regenerate") &&
              SKILL_D("force/regenerate")->exert(me, me))
         {
              // try to regenerate & learn again
           write("你觉得精神好了一些，继续进行研究。\n");
           pertimes--;
           continue;
         } else
         {
	          me->set("jing", 0);
            break;
         }
      }
      me->add("learned_points", 1);
     	me->receive_damage("jing", jing_cost );
		}
	}
	if (pertimes <= 0)
		return notify_fail("你今天太累了，结果什么也没有研究成。\n");

	for(i=0;i<pertimes;i++)
//		me->improve_skill(skill, random((int)me->query_int()/2));
		me->improve_skill(skill, (int)me->query_int()/8+random((int)me->query_int()/4));
	if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
	printf("你研究了一会，对「%s」这一招似乎想通了些什么。\n", skill_name);
	else
	printf("你研究了一会，似乎对"+to_chinese(skill)+"有些新的领悟。\n");
	if (pertimes < times)
	return notify_fail("但是你今天太累了，研究了"+chinese_number(pertimes) +"次以后只好先停下来。\n");

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : research | yanjiu <技能> <次数>

    这个指令可以让你研究一种技能的疑难问题，当你师傅这项技能的级
别不如你的时候，可以通过研究自己来提高，当然进步的速度是不如向师
傅学的了。

    此外研究也需要消耗一些精气和潜能，而消耗的精气跟你自己的悟性
有关。

其他相关指令 : apprentice, practice, skills, study, learn
HELP
	);
	return 1;
}

