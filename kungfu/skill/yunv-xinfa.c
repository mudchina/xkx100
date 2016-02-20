// yunv-xinfa.c 玉女心法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{

	if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳难调，不能修习玉女心法。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("玉女心法只能用学(learn)来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunv-xinfa/" + func;
}

int help(object me)
{
	write(HIC"\n玉女心法："NOR"\n");
	write(@HELP

    古墓内功讲究一个“静”字，唯有平心静气、摆脱世俗之扰才
能修习上乘武功。玉女心经修炼难度很大，学习者要不急不躁，循
序渐进方有成功之望。可以寻觅本门秘籍《玉女心经》上下册研读。

	学习要求：
		基本内功10级
		不能做太监
HELP
	);
	return 1;
}

