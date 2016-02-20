// xiaowuxiang.c 小无相功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("xiaowuxiang", 1);

	if (((string)me->query("class") != "lama") && i > 29)
		return notify_fail("你不是僧人，学不了高深的小无相功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学小无相功。\n");

	if ( me->query("gender") == "无性" && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的小无相功。\n");

//       if (i > 10 && (int)me->query("shen") < t * 100)
  //      	return notify_fail("要学小无相功，你的表现还不够吧！ \n");


	return valid_public(me,"longxiang");
}

int practice_skill(object me)
{
	return notify_fail("小无相功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiaowuxiang/" + func;
}
int help(object me)
{
	write(HIC"\n小无相功："NOR"\n");
	write(@HELP

    小无相功乃北宋年间逍遥派的内功之一，逍遥内功分为北冥神
功，八荒六合唯我独尊功及小无相功三种，逍遥派掌门逍遥子精通
北冥神功，天山童姥专擅八荒六合唯我独尊功，其师妹西夏太后李
秋水则得授小无相功作为防身绝技，后为吐蕃国师鸠摩智所得，成
为雪山派内功。小无相功精微奥妙，以之催动雪山绝技之火焰刀，
威力不在少林绝艺之下。

	学习要求：
		非出家为喇嘛学不到30级以上的小无相功
		太监学不到50级以上的小无相功
		基本内功10
		相应的正气
HELP
	);
	return 1;
}

