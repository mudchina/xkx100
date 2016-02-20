// literate.c 读书写字
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 20; }
int power_point(object me) { return 1; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
//	if ( me->query("class") != "bonze" )
//		return notify_fail("你现在不能学习读书写字。\n");
	return 1;
}

int help(object me)
{
	write(HIC"\n读书写字："NOR"\n");
	write(@HELP

    读书写字是自学武籍的基础，并能改善你后天的悟性。

	学习要求：
		无
HELP
	);
	return 1;
}

