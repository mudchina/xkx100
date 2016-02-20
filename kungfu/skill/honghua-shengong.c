// honghua-shengong.c 红花神功
// Last Modified by winder on Sep. 12 2001

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
	int i = (int)me->query_skill("honghua-shengong", 1);
	int t = 1, j;

	if(i <= 100) for (j = 1; j < i / 10; j++) t *= 2;

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");
	if(i <= 100)
	{
		if (i > 10 && (int)me->query("shen") < t * 100) 
			return notify_fail("你的侠义正气太低了，无法领会更高深的红花神功。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("你的侠义正气太低了，无法领会更高深的红花神功。\n");
	}
	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("红花神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"honghua-shengong/" + func;
}
int help(object me)
{
	write(HIM"\n红花神功："NOR"\n");
	write(@HELP

    红花会弟子内功，具自疗、他疗及运功之用。

	学习要求：
		基本内功10级
		相应的正气
HELP
	);
	return 1;
}
