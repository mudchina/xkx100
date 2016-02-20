// zhanzhuang-gong.c 南少林 四平大马站桩功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i, nb, nf, nh, ns, ts;

	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("zhanzhuang-gong", 1);
	ns = (int)me->query("guilty");

	if ( me->query("couple/have_couple") )
		return notify_fail("你尘缘未了，无法学习四平大马站桩功！\n");
	if ( me->query("sex/number") )
		return notify_fail("你已经破了色戒，无法再学习四平大马站桩功！\n");
	if ( nb < 100 && nb <= nh )
		return notify_fail("你的禅宗心法修为不够，无法领会更高深的四平大马站桩功。\n");
	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会四平大马站桩功。\n");
	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的四平大马站桩功。\n");

  return valid_public(me,"yijinjing");
}

int practice_skill(object me)
{
	return notify_fail("四平大马站桩功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"zhanzhuang-gong/" + func;
}
int help(object me)
{
	write(HIC"\n站桩功："NOR"\n");
	write(@HELP

    站桩功全称四平大马站桩功，为南少林派本门内功。
    南少林特注重根基。要求弟子马步站稳，日日都需练习。四平指的是
扎马步桩时，头平、肩平、手平和膝平。练习时，常放置水碗于这些部位，
练习过程中，不允许水溢出。

	学习要求：
		基本内功10级
		禅宗心法修为不低于四平大马站桩功
		不犯其它戒律
HELP
	);
	return 1;
}

