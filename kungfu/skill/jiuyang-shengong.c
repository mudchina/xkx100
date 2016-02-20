// jiuyang-shengong.c 九阳神功
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
	int lvl = (int)me->query_skill("jiuyang-shengong", 1);

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够，还不能学习九阳神功。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("九阳神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}

int help(object me)
{
	write(HIC"\n九阳神功："NOR"\n");
	write(@HELP

    九阳神功来自《九阳真经》。
    在少林寺中的一部《楞伽经》中的夹缝之中，达摩祖师亲手书
写的一部经书，称为《九阳真经》。《九阳真经》中记着许多强身
健体、易筋洗髓的法门，觉远大师依此练习。后潇湘子和尹克西盗
得此书，为逃避追缴，置入猿腹。直到百年之后，方被张无忌在昆
仑仙境的白猿腹中偶然取得，九阳神功才重见天日。

    〖特殊功效〗

	学习要求：
		基本内功10级
HELP
	);
	return 1;
}

