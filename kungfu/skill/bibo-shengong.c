// bibo-shengong.c 碧波神功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("bibo-shengong", 1);

	if ( me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功还不到火候。\n");
	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的碧波神功。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("碧波神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"bibo-shengong/" + func;
}
int help(object me)
{
	write(HIC"\n碧波神功："NOR"\n");
	write(@HELP

    这是东海桃花岛黄药师所创的一门内功心法。传说当初黄药师行
船海上，忽见碧海潮生，碧波汹涌，声势惊人，在与风浪搏斗之余，
豁然顿悟，创出一门阳刚阴柔相结合的内功，此谓碧波神功。

	学习要求：
		基本内功10级
		太监无法领悟50级以上的碧波神功
HELP
	);
	return 1;
}

