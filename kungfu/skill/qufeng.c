// qufeng.c 驱蜂之术
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	if ((int)me->query_skill("yunv-xinfa", 1) < 10)
		return notify_fail("你的玉女心法火候不够，无法学驱蜂之术。\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("你的内力太弱，无法学习驱蜂之术。\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("驱蜂之术只能靠学习来提高。\n");
}
int help(object me)
{
	write(HIC"\n驱蜂之术："NOR"\n");
	write(@HELP

    古墓弟子如果身具驱蜂术，使用蜂浆瓶即可驱蜂克敌。
    请help qufeng。

	学习要求：
		玉女心法10级
		内力30
HELP
	);
	return 1;
}

