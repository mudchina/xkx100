// array.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n基本阵法："NOR"\n");
	write(@HELP

    桃花岛弟子布阵所用基本技能。

	学习要求：
		无
HELP
	);
	return 1;
}

