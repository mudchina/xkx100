// yunlong-shengong.c 云龙神功
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
	int i, nb, nf, nh, ns, ts;
	nb = (int)me->query_skill("yunlong-xinfa", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("yunlong-shengong", 1);

	if ( me->query("gender") == "无性" && nh > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的云龙神功。\n");

  if ( nb < 100 && nb <= nh )
		return notify_fail("你的云龙心法修为不够，无法领会更高深的云龙神功。\n");

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会云龙神功。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("云龙内功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunlong-shengong/" + func;
}
int help(object me)
{
	write(HIC"\n云龙神功："NOR"\n");
	write(@HELP

    天地会本门内功，具有自疗及运功之特殊用途。


	学习要求：
		相应的云龙心法
		基本内功10级
		太监无法学到高等级的云龙神功
HELP
	);
	return 1;
}

