// begging.c 叫化绝活
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
	write(HIC"\n叫化绝活："NOR"\n");
	write(@HELP

    丐帮乞讨技能。丐帮弟子不能购买物品，乞讨是获得物品的一
种手段。乞讨(beg) 不成功不会带来对方的攻击。

	学习要求：
		无
HELP
	);
	return 1;
}

