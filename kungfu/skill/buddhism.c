// buddhism.c 禅宗心法
// Last Modified by winder on Mar. 10 2000

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
	if( (int)me->query("guilty") > 0 )
		return notify_fail("你屡犯僧家数戒，尘俗之心太重，无法修炼禅宗心法。\n");
	if ( me->query_skill("taoism",1) > 1)
		return notify_fail("你已学了道学心法，怎么能修炼禅宗心法？\n");
	if ((me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail("你已学了华山心法，不能修炼禅宗心法。\n");
	if (me->query("class") != "bonze")
		return notify_fail("你凡心重，不出家，怎么能修炼禅宗心法。\n");
	if (me->query_skill("buddhism", 1) >= 150)
		return notify_fail("限于资质，你对禅宗心法的理解也就到此为止了。\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("禅宗心法只能靠学(learn)来提高。\n");
}

int help(object me)
{
	write(HIC"\n禅宗心法："NOR"\n");
	write(@HELP

    少林弟子的必修课。少林派创派祖师达摩乃是天竺禅宗大师，
又是东土禅宗第一祖，少林弟子自应以修习禅宗，精研佛法为任。
配合混元一气功可以长精，精增加的程度取决于混元一气功和禅宗
心法等级的高低。

	学习要求：
		犯戒或非出家人无法领悟
                与道家心法和紫氲吟不能兼学
HELP
	);
	return 1;
}

