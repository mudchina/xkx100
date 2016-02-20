// gambling.c 基本赌技
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
	if ( me->query("age") <= 20 )
		return notify_fail("你现在还太小，不能学习基本赌技。\n");
	return 1;
}

int help(object me)
{
	write(HIC"\n基本赌技："NOR"\n");
	write(@HELP

    基本赌技是一种江湖技艺。通过在赌场中赌博，可以用金银和
技能下注，获得利益。

	学习要求：
		赌博
HELP
	);
	return 1;
}

