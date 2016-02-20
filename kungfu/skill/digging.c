// digging.c 掘地之术
// Last Modified by winder on Jun. 10 2000

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
	int lvl;

	lvl = (int)me->query_skill("construction", 1);

	if (lvl > 29 && me->query("kar") != 27) 
		return notify_fail("限于天资，你只能修习这个程度了。\n");
	else return 1;
}

int practice_skill(object me)
{
	return notify_fail("掘地之术只能靠学习来提高。\n");
}
int help(object me)
{
	write(HIC"\n掘地之术："NOR"\n");
	write(@HELP

    掘地之术是神龙岛独门绝技。

	学习要求：
		无。
HELP
	);
	return 1;
}

