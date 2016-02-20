// chengzi18po.c 城字十八破
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point() { return 1; }

void skill_improved(object me) {}

int valid_learn(object me)
{
	if(me->query_skill("qingming-xuangong", 1) + random(5) <
		me->query_skill("chengzi18po", 1))
		return notify_fail("你的本门内功未到火候，无法继续修习城字十八破。\n");
	return 1;
}

int help(object me)
{
	write(HIC"\n城字十八破："NOR"\n");
	write(@HELP

    “城字十八破”与“青字九打”并列为青城镇山武功，配套兵
器是雷公轰。

	学习要求：
		相应级别的青冥玄功
HELP
	);
	return 1;
}

