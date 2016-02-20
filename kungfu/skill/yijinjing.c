// yijinjing.c 少林 易筋经神功
// Last Modified by sega on Mar. 10 2000
// Feb.21 1998 by Java

#include <ansi.h>
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	mapping skl = me->query_skills();
	string *sk;
	string skl_name = explode(__FILE__, "/")[<1][0..<3];
	int i, nb, nf, oh, oh1, nh, ns, ts;
	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	oh = (int)me->query_skill("hunyuan-yiqi", 1);
	oh1 = (int)me->query_skill("zhanzhuang-gong", 1);
	nh = (int)me->query_skill("yijinjing", 1);
	ns = (int)me->query("guilty");

	if ( oh + oh1 < 100 )
		return notify_fail("你的少林内功太低，无法学习易筋经神功！\n");
	if ( me->query("couple/have_couple") )
		return notify_fail("你尘缘未了，无法再学习易筋经神功！\n");
	if ( me->query("sex/number") )
		return notify_fail("你已经破了色戒，无法再学习易筋经神功！\n");
	if ( me->query("gender") != "男性" )
		return notify_fail("你非童男之体，不能练习易筋经神功。\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("你的禅宗心法修为不够，无法领会更高深的易筋经神功。\n");

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会易筋经神功。\n");

	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的易筋经神功。\n");

	return valid_public(me,({"zhanzhuang-gong","hunyuan-yiqi"}));
}

int practice_skill(object me)
{
	return notify_fail("易筋经神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yijinjing/" + func;
}

//add by sega
mixed be_hit_ob(object me,object victim,int damage_bonus,int factor)

//factor= 加力 damage_bonus=臂力 .
{
	int ap,dp;
//内功相差太多(至少2倍以上),内力伤害全部抵消,基本上不出现
	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	if ((int)random(ap/2)>dp && me->query("neili")>2000)
	{

		if (random(10)==1) tell_object(victim, "你只觉得如同击在金属上，头脑里闪过一个念头：金属罩！\n");
		else tell_object(victim,HIY"你只觉得劲力如同击在金属罩，根本无法伤他分毫！\n"NOR);
		tell_object(me, HIY"你只觉得劲力袭体，急忙运起金钟罩神功，一股真气弥漫全身！\n"NOR);
		me->add("neili",-2*damage_bonus);
		return -damage_bonus;
	}
	else if ((random(ap*2)>dp) && me->query("neili")>1500)
	{
		if (random(10)==1) tell_object(victim,HIY"你只觉得如同击在金属上，头脑里闪过一个念头：“金属罩”！\n"NOR);
		else tell_object(victim,HIY"你只觉得劲力如同击在金属上，虎口隐隐作痛！\n"NOR);
		tell_object(me, HIY"你只觉得劲力袭体，勉力运起金钟罩，一股真气弥漫全身！\n"NOR);
		me->add("neili",-damage_bonus);
		return -random(damage_bonus);
	}
	return 0;
}

int help(object me)
{
	write(HIC"\n易筋经神功："NOR"\n");
	write(@HELP

    《易筋》，《洗髓》二经向为少林镇寺之宝，相传为达摩祖师
所创，载有不少天竺高僧的瑜伽秘术，但由于其习练艰难，须得勘
破“我相，人相”，心中不存修习武功之念，故历代弟子罕有练成
者。
    《洗髓》记载天下所有武功的精要，《易筋》则是一门极其高
深的内功心法书籍。

	学习要求：
		未破色戒的童男之身
		未犯戒
		混元一气功100级
		相应级别的禅宗心法
HELP
	);
	return 1;
}

