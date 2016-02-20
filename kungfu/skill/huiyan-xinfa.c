// huiyan-xinfa.c 回雁心法
// Last Modified by ahda on Aug.30 2001

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
	int lvl = (int)me->query_skill("huiyan-xinfa", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的回雁心法。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100) 
			return notify_fail("你的侠义正气太低了，无法领会更高深的回雁心法。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
			return notify_fail("你的侠义正气太低了，无法领会更高深的回雁心法。\n");
	}

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("回雁心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"huiyan-xinfa/" + func;
}

int help(object me)
{
	write(HIC"\n回雁心法："NOR"\n");
	write(@HELP

    回雁心法乃衡山派镇山武学，为衡山派前辈高人所创，是
    修习衡山派各种高深武功的根基，有延年益寿之功效。

	学习要求：
		基本内功10级
		相应的正气
		太监无法领悟50级以上的回雁心法
HELP
	);
	return 1;
}

