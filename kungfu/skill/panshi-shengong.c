// panshi-shengong.c 磐石神功
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

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够，还不能学习磐石神功。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("磐石神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"panshi-shengong/" + func;
}
int help(object me)
{
	write(HIM"\n磐石神功："NOR"\n");
	write(@HELP

    泰山派内功，具自疗及运功之用。

	学习要求：
		基本内功10级
HELP
	);
	return 1;
}

