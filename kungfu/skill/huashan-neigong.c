// huashan-neigong.c 华山内功
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
// need more limit here
{
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("你的紫霞神功火候还不够。\n");
	return valid_public(me,"zixia-shengong");
}

int practice_skill(object me)
{
	return notify_fail("华山气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D(__DIR__"huashan-neigong/") + func;
}

int help(object me)
{
	write(HIC"\n华山内功："NOR"\n");
	write(@HELP

    华山内功为华山剑宗本门内功心法。

	学习要求：
		紫霞神功10级
HELP
	);
	return 1;
}

