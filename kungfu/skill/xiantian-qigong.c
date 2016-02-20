// xiantian-qigong.c 先天气功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("xiantian-qigong", 1);
	int t = 1, j;
	if (lvl<=100) for (j = 1; j < lvl / 10; j++) t*=2;

	if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调，难以修行玄门正宗的先天气功。\n");

	if ( me->query("class") == "bonze" )
		return notify_fail(RANK_D->query_respect(me)+"欲修我道家玄门气功，怎又去入了佛门？\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100)
			return notify_fail("你的侠义正气太低了。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000))
			return notify_fail("你的侠义正气太低了。\n");
	}

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("先天气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-qigong/" + func;
}

int help(object me)
{
	write(HIC"\n先天气功："NOR"\n");
	write(@HELP

    先天功是天下内功正宗，是全真教其它武功的基础。先天功讲
究根基扎实，所以入门较慢，但练到后面，自然加快。先天功修行
步骤共分九节，即丹田生精，炼神入顶，金液还丹，周天火候，龙
虎交媾，太阳炼形，三田既济，炼神合道，弃壳升仙，超凡入圣。

	学习要求：
		基本内功10级
		不能做太监或和尚
		相应的正气
HELP
	);
	return 1;
}

