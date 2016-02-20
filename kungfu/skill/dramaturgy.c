// dramaturgy.c 梨园旧艺
// Last Modified by winder on Jun. 10 2000

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
	int lvl;

	lvl = (int)me->query_skill("dramaturgy", 1);

	if (lvl > 29 && me->query("kar") != 25) 
		return notify_fail("限于天资，你只能修习这个程度了。\n");
	else return 1;
}

int practice_skill(object me)
{
	return notify_fail("梨园旧艺只能靠学习来提高。\n");
}
int help(object me)
{
	write(HIC"\n梨园旧艺："NOR"\n");
	write(@HELP

    逍遥派祖师逍遥子学究天人，胸中所学包罗万象。他共传下七
门绝艺：绕梁琴艺 (luteplaying)、纹枰手谈 (goplaying)、泼墨
丹青(painting)、济世之术(medicine)、土木机关(construction)、
园艺莳花(horticulture)、梨园旧艺(dramaturgy)。

	学习要求：
		无。但天赋才气限制了对更高深境界的努力
HELP
	);
	return 1;
}

