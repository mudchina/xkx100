// kuihua-xinfa.c 葵花心法
// Last Modified by winder on Mar. 10 2000

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
	int i = (int)me->query_skill("kuihua-xinfa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学葵花心法。\n");
	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("学葵花心法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("你练了秃驴牛鼻子们的心法，还学葵花心法做什麽！\n");

	return valid_public(me,"xixing-dafa");
}

int practice_skill(object me)
{
	return notify_fail("葵花心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"kuihua-xinfa/" + func;
}

int help(object me)
{
	write(HIC"\n葵花心法："NOR"\n");
	write(@HELP

    葵花心法为日月神教黑木崖本门内功心法。

	学习要求：
		基本内功10级
		相应的戾气
		不能学禅宗心法和道家心法
HELP
	);
	return 1;
}

