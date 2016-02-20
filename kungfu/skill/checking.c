// checking.c 道听途说
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point() { return 1; }

int help(object me)
{
	write(HIC"\n道听途说："NOR"\n");
	write(@HELP

    丐帮帮众遍及大江南北，消息灵通，凡江湖上发生什么事，往
往他们最先得知。身具此艺的丐帮帮众，可以在江湖上打探(check)
别人的消息。

	学习要求：
		无
HELP
	);
	return 1;
}

