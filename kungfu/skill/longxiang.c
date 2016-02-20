// longxiang.c 龙象般若功
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
	int i = (int)me->query_skill("longxiang", 1);
     //   int t = 1, j;
     //	for (j = 1; j < i / 10; j++) t*= 2;

	if (((string)me->query("class") != "lama") && i > 29)
		return notify_fail("你不是僧人，学不了高深的龙象般若功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学龙象般若功。\n");

	if ( me->query("gender") == "无性" && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的龙象般若功。\n");

	if (i > 10 && (int)me->query("shen") >  - i * 1000)
		return notify_fail("要学龙象般若功，你的表现还不够吧！ \n");
  return valid_public(me,"xiaowuxiang");
}

int practice_skill(object me)
{
	return notify_fail("龙象般若功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"longxiang/" + func;
}
int help(object me)
{
	write(HIC"\n龙象般若功："NOR"\n");
	write(@HELP

    “龙象般若功”，那是密宗中至高无上的护法神功。为雪山派
本门内功。【龙象般若经】言道，功成十层以上，每出一招，均具
十龙十象的大力，故名“龙象般若功”。

    “龙象般若功”共分十三层，第一层功夫十分浅易，纵是下愚
之人，只要得到传授，一二年中即能练成。第二层比第一层加深一
倍，需时三四年。第三层又比第二层加深一倍，需时七八年。如此
成倍递增，越是往后，越难进展。待到第五层以后，欲再练深一层，
往往便须三十年以上苦功。密宗一门，高僧奇士历代辈出，但这一
十三层“龙象般若功”却从未有一人练到十层以上。这功夫循序渐
进，本来绝无不能练成之理，若有人得享千岁高龄，最终必臻第十
三层境界，只是人寿有限，密宗中的高僧修士欲在天年终了之前练
到第七层、第八层，便非得躁进不可，这一来，往往陷入了欲速不
达的大危境。北宋年间，藏边曾有一位高僧练到了第九层，继续勇
猛精进，待练到第十层时，心魔骤起，无法自制，终于狂舞七日七
夜，自终绝脉而死。

	学习要求：
		基本内功10级
		相应的戾气
		非出家喇嘛不能学到30级以上的龙象般若功
		太监不能学到50级以上的龙象般若功
HELP
	);
	return 1;
}

