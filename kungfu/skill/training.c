// training.c 驭兽术
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "knowledge"; }

int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n驭兽术："NOR"\n"); 
	write(@HELP

    驭兽术是驱使动物的技能。唯丐帮弟子和白驼山弟子能学到。
    请help train和help transport。

	学习要求：
		无
HELP
	);
	return 1;
}

