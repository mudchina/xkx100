// spear.c 基本枪法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "martial"; }
string martialtype() { return "skill"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n基本枪法："NOR"\n");
	write(@HELP

    枪类武技的基本功。
    枪是历代重要兵器之一，为「百兵之王」。武林中人称「百日
刀、千日枪、万日剑」，上阵冲锋枪为首选。

	学习要求：
		无
HELP
	);
	return 1;
}

