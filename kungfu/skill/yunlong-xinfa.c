// yunlong-xinfa.c 云龙心法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int practice_skill(object me)
{	
	return notify_fail("云龙心法只能靠学(learn)来提高。\n");
}
int help(object me)
{
	write(HIC"\n云龙心法："NOR"\n");
	write(@HELP

    云龙心法是云龙门的精神支柱。用以激励天地会众反清复明。

	学习要求：
		无
HELP
	);
	return 1;
}

