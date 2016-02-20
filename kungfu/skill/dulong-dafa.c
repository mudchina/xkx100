// dulong-dafa.c 蛇岛  毒龙大法
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
	mapping skills;
	string *sname;

	int lvl = (int)me->query_skill("dulong-dafa", 1);
	int t = 1, i, j;
	int other_force = 0;

	for (j = 1; j < lvl / 10; j++) t *= 2;
/*
	if (!me->query("yijin_wan"))
		return notify_fail("你未曾服食教主的豹胎易经丸，没有根基，无法学习毒龙大法。\n");

	if (me->query("yijin_wan") < me->query("age") - 13 )
		return notify_fail("你未曾每年按期服食教主的豹胎易经丸，无法继续学习毒龙大法。\n");

*/
	if ( (int)me->query_skill("force", 1) < 10 ||
		(int)me->query_skill("force", 1)/2 < lvl/3 )
		return notify_fail("你的基本内功火候还不够，无法领会毒龙大法。\n");
	if (lvl > 10 && (int)me->query("shen") > t * 100 &&
		(me->query_skill("taoism", 1) ||
		me->query_skill("buddhism", 1)) )
		return notify_fail("你尚不适宜学习毒龙大法。\n");
	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("毒龙大法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"dulong-dafa/" + func;
}

int help(object me)
{
	write(HIC"\n毒龙大法："NOR"\n");
	write(@HELP

    毒龙大法为神龙教本门内功。

	学习要求：
		基本内功10级
		不能修习禅宗或道家心法
HELP
	);
/*		定期服食豹胎易经丸 */
	return 1;
}

