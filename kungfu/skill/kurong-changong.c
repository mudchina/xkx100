// kurong-changong.c 枯荣禅功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	if ( me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功不到火候，难以领会枯荣禅功。\n");
	if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调，难以领会高深的枯荣禅功。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("枯荣禅功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"kurong-changong/" + func;
}


int help(object me)
{
	write(HIC"\n枯荣禅功："NOR"\n");
	write(@HELP

    有常无常，双树枯荣，南北西东，非假非空！
    佛门奇功，天龙寺枯荣长老精擅此技。相传释迦牟尼在桫椤双
树之间入灭，代表了非枯非荣、非假非空的最高境界，后世弟子便
以此为修行之法，静参枯禅。是为枯荣禅功之来由。
    为天南大理段家的本门内功。

	学习要求：
		基本内功10级
		不能是太监
HELP
	);
	return 1;
}

