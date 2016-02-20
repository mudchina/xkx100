// stealing.c 妙手空空
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
	write(HIC"\n妙手空空："NOR"\n");
	write(@HELP

    妙手空空是丐帮谋生伎俩。
    请help steal。

	学习要求：
		无
HELP
	);
	return 1;
}

