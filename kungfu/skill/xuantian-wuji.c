// xuantian-wuji 玄天无极功

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int nl, ng, nf, nx;
	nf = (int)me->query_skill("force", 1);
	ng = (int)me->query_skill("goplaying", 1);
	nl = (int)me->query_skill("luteplaying", 1);
	nx = (int)me->query_skill("xuantian-wuji", 1);

	if ( nf < 20)
		return notify_fail("你的基本内功火候还不够，无法领会玄天无极功。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("玄天无极功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"xuantian-wuji/" + func;
}
int help(object me)
{
	write(HIC"\n玄天无极功："NOR"\n");
	write(@HELP

    玄天无极功是昆仑派的本门内功。

	学习要求：
		基本内功10级
		相当的琴棋技艺的造诣
HELP
	);
	return 1;
}

