// acupuncture.c 针灸之术
// Last modified by winder 2003.9.2

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
        if ((int)me->query_skill("medicine", 1) < 50)
                return notify_fail("你的济世之术造诣太浅，无法领会针灸之术。\n");
        if ((int)me->query_skill("medicine", 1) <
		(int)me->query_skill("acupuncture", 1))
                return notify_fail("你的济世之术有限，无法掌握更深奥的针灸之术。\n");
        return 1;
}
int practice_skill(object me)
{
	return notify_fail("针灸之术只能靠学习来提高。\n");
}
int help(object me)
{
	write(HIC"\n针灸之术："NOR"\n");
	write(@HELP

    精通针灸之术，可以悠游天下，治病救人。

	学习要求：
		针灸之术限制了对更高深境界的努力
HELP
	);
	return 1;
}

