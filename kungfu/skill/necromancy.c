// necromancy.c 降伏法
// Last Modified by winder on Mar. 10 2000
// by Java

#include <ansi.h>
inherit SKILL;
string type() { return "knowledge"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	if( (int)me->query_skill("longxiang",1) <
		(int)me->query_skill("necromancy",1) )
		return notify_fail("你的龙相般若功太低了，无法修炼更高深的降伏法。\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("降伏法只能靠学(learn)来提高。\n");
}

int help(object me)
{
	write(HIC"\n降伏法："NOR"\n");
	write(@HELP

    降伏法为密宗密技，身为密宗弟子，且有相当的降伏法修为，
可利用慑心术诱惑某人做把身上的东西给你, 或往那里离开，或者
跟着你。对方如果内功深厚，而你学艺不精，必然也会招致以牙还
牙。
    请help shexin。

	学习要求：
		龙象般若功等级不能低于降伏法等级
HELP
	);
	return 1;
}

