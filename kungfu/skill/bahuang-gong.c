// bahuang-gong.c 八荒六合唯我独尊功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;

string type() { return "martial"; }
string martialtype() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	if ((string)me->query("family/master_id")!="ju jian"
	&& (string)me->query("family/master_id")!="mei jian"
	&& (string)me->query("family/master_id")!="tong lao"
	&& (string)me->query("family/master_id")!="xu zhu")
	return notify_fail("只有灵鹫宫门下弟子才能学习八荒六合唯我独尊功。\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");
	return valid_public(me,"beiming-shengong");
}
int practice_skill(object me)
{
	return notify_fail("八荒六合唯我独尊功只能用学(learn)的来提高。\n");
}
string exert_function_file(string func)
{
	return __DIR__"bahuang-gong/" + func;
}
int help(object me)
{
	write(HIC"\n八荒六合唯我独尊功："NOR"\n");
	write(@HELP

    八荒六合唯我独尊功是灵鹫宫至高无上的内功，须以最上乘内
功为根基。这功夫威力奇大，却有一个大大的不利之处，每三十年，
便要返老还童一次。

	学习要求：
		灵鹫宫弟子
		基本内功10级
HELP
	);
	return 1;
}

