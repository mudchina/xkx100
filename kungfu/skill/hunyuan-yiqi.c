// hunyuan-yiqi.c 少林 混元一气功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i, nb, nf, nh, ns, ts;

	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("hunyuan-yiqi", 1);
	ns = (int)me->query("guilty");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	if ( me->query("couple/have_couple") )
		return notify_fail("你尘缘未了，无法再学习混元一气功！\n");

	if ( me->query("sex/number") )
		return notify_fail("你已经破了色戒，无法再学习混元一气功！\n");

	if ( me->query("gender") != "男性" )
		return notify_fail("你非童男之体，不能练习混元一气功。\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("你的禅宗心法修为不够，无法领会更高深的混元一气功。\n");

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会混元一气功。\n");

	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的混元一气功。\n");

	return valid_public(me,"yijinjing");
}

int practice_skill(object me)
{
	return notify_fail("混元一气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"hunyuan-yiqi/" + func;
}
int help(object me)
{
	write(HIC"\n混元一气功："NOR"\n");
	write(@HELP

    混元一气功为少林派本门内功。

	学习要求：
		基本内功10级
		不能破色戒的童男之身
		禅宗心法修为不低于混元一气功
		不犯其它戒律
HELP
	);
	return 1;
}

