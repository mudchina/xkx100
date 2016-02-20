// /cmds/skill/jiao.c

// Modified by Constant Jan 11 2001
// Modified by Zeratul Jan 11 2001 teach增加了时间限制，呵呵
inherit F_CLEAN_UP;

#include <skill.h>
#include <ansi.h>



void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, student, skill_name;
	object ob;
	int student_skill, my_skill, gin_cost, grade, student_combat_exp;
	int improve_points;

	if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");

	if(!arg || (sscanf(arg, "%s %s", student, skill)!=2 ))
		return notify_fail("指令格式：teach <某人> <技能>\n");

	if( me->is_fighting() ) return notify_fail("临阵磨枪？来不及啦。\n");

	if(!me->query("couple/have_couple")) 
		return notify_fail("你还没有伴侣呢！\n");

	if( !(ob = present(student, environment(me))) || !ob->is_character())
		return notify_fail("你要教谁？\n");

	if( student != me->query("couple/couple_id") ||
		me->query("id") != ob->query("couple/couple_id") )
	{
		if ((string)me->query("gender") == "女性") 
			return notify_fail("他不是你的丈夫。\n");
		else return notify_fail("她不是你的妻子。\n"); }
	
	if ( time() - me->query("last_sleep_couple") > 259200 ||
		time() - ob->query("last_sleep_couple") > 259200 )
		return notify_fail("你们夫妻太长时间没有交流，感情生疏了，教什么也学不会。\n");

	if( !living(ob) )
		return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

	if (ob->is_busy())
		return notify_fail(ob->name() + "现在正忙着呢。\n");

	if( ob->is_fighting() ) return notify_fail("临阵磨枪？来不及啦。\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("这项技能你还不会呢！\n");

	if( ob->prevent_learn(me, skill) ) return 0;

	student_skill = ob->query_skill(skill, 1);

	if( my_skill <= student_skill )
		return notify_fail("这项技能" + ob->name() + "的程度已经不输于你了。\n");

	if( !SKILL_D(skill)->valid_learn(ob) ) 
		return notify_fail("依" + ob->name() + "目前的能力，没有办法学习这种技能。\n");

	gin_cost = 300 / ((int)me->query("int") + (int)ob->query("int"));

	if( !student_skill )
	{
		gin_cost *= 2;
		ob->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("你的潜能已经发挥到极限了，没有办法再教了。\n");

	if( (int)ob->query("learned_points") >= (int)ob->query("potential") )
		return notify_fail(ob->name() + "的潜能已经发挥到极限了，没有办法再成长了。\n");

	printf("你向%s解释有关「%s」的疑问。\n", ob->name(),
		to_chinese(skill));

	if( ob->query("env/no_learn") )
		return notify_fail("但是" + ob->name() + "现在并不准备听你解释问题。\n");

	tell_object(ob, sprintf("%s向你解释有关「%s」的问题。\n",
		me->name(), to_chinese(skill)));

	if( (int)me->query("jing") > gin_cost ) {
		if( userp(me) ) me->receive_damage("jing", gin_cost );
	} else {
		write("但是你太累了，没有办法再教" + ob->name() + "。\n");
		tell_object(ob, "但是" + me->name() + "显然太累了，没有办法教你什麽。\n");
		return 1;
	}
		
	student_combat_exp = (int)ob->query("combat_exp");

	if(student_combat_exp < 1000000)
		grade = 1;
	else if(student_combat_exp < 8000000)
		grade = 2;
	else if(student_combat_exp < 30000000)
		grade = 3;
	else
		grade = 4;

	if((int)ob->query("jing") > gin_cost )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&& student_skill * student_skill * student_skill / 10 > student_combat_exp)
		{
			tell_object(ob, "也许是缺乏实战经验，你对" + me->name() + "的解释总是无法领会。\n");
		}
		else
		{
		if(skill_name = SKILL_D(skill)->query_skill_name(student_skill))
			tell_object(ob, "你听了" + me->name() + "的指导，对" + skill_name + "这一招似乎有些心得。\n");
		else
			tell_object(ob,"你听了" + me->name() + "的指导，似乎有些心得。\n");

			me->add("learned_points", 1);
			ob->add("learned_points", 1);
			
// 学习速度 = 双方先天悟性的和的一半，加武功学习补偿。
// 未定义学习补偿的技能，默认学习补偿为10。
			improve_points = (me->query("int")+ob->query("int"))/2;
			if(SKILL_D(skill)->learn_bonus())
				improve_points += SKILL_D(skill)->learn_bonus();
			else improve_points += 10;
// 调整夫妻间学习技能的速度，加重对离婚的惩罚。
			improve_points = improve_points * grade / (me->query("divorce") + ob->query("divorce") + 1);
			if (improve_points < 10) improve_points = 10;
			improve_points = random(improve_points);

			ob->improve_skill(skill, improve_points);
		}
	}
	else
	{
		gin_cost = ob->query("jing");
		tell_object(ob, "你今天太累了，结果什么也没有学到。\n");
	}

	ob->receive_damage("jing", gin_cost );

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : teach | jiao <某人> <技能>
 
这个指令可以让你向你的伴侣解释有关某一种技能的疑难问题，当然，你的伴侣在这
项技能上的造诣必须比你低，而你的伴侣经由这种方式学习得来的技能也不可能高於
你，然而因为这种传授方式相当於一种「经验的传承」，因此这可以说是熟悉一种新
技能较快的方法。

此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你的伴侣的悟性，以及二
人的恩爱程度有关。

其他相关指令 : apprentice, practice, skills, study, learn
HELP
	);
	return 1;
}

