// sword.c 基本剑法
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
	write(HIC"\n基本剑法："NOR"\n");
	write(@HELP

    剑类武技的基本功。
    剑，号称「百兵之君」。剑诀云：「剑是青龙剑走剑要平善，
气要随剑行，两眼顾剑尖，气沉两足稳，身法需自然，剑行如飞燕，
剑落如停风，剑收如花絮，剑刺如钢钉。」

	学习要求：
		无
HELP
	);
	return 1;
}

