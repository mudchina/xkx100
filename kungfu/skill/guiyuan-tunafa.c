// guiyuan-tunafa.c 铁掌帮 归元吐纳法
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
#include "force.h"
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int valid_enable(string usage) { return usage == "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	int nf;
	
	nf = (int)me->query_skill("force", 1);
	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会归元吐呐法。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("归元吐呐法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"guiyuan-tunafa/" + func;
}
int help(object me)
{
	write(HIM"\n归元吐纳法："NOR"\n");
	write(@HELP

    铁掌帮的内功，具自疗、他疗及运功之用。

	学习要求：
		基本内功10级
HELP
	);
	return 1;
}

