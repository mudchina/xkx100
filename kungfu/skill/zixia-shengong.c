// zixia-shengong.c 紫霞神功
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
	int i = (int)me->query_skill("zixia-shengong", 1);
	int t = 1, j;

	if(i <= 100) for (j = 1; j < i / 10; j++) t *= 2;

	if ( me->query("gender") == "无性" && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的紫霞神功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够，还不能学习紫霞神功。\n");

	if(i<=100)
	{
		if (i > 10 && (int)me->query("shen") < t * 100) 
			return notify_fail("你的侠义正气太低了，无法领会更高深的紫霞神功。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("你的侠义正气太低了，无法领会更高深的紫霞神功。\n");
	}


	return valid_public(me,"huashan-neigong");
}

int practice_skill(object me)
{
	return notify_fail("紫霞神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"zixia-shengong/" + func;
}
int help(object me)
{
	write(HIM"\n紫霞神功："NOR"\n");
	write(@HELP

    华山气宗内功，具自疗及运功之用，并能增加精气。精的增加
视乎于自身紫氤吟的修为，气的增加则决定于自身正气诀的修为。

	学习要求：
		基本内功10级
		相应的正气
		太监无法学到50级以上的紫霞神功
HELP
	);
	return 1;
}

