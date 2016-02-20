// xidu-poison.c 西毒毒技
// Last Modified by winder on Mar. 10 2000
// Modified by Java Mar.1998

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
	mapping myfam;
	myfam = (mapping)me->query("family");
	if (!myfam || (myfam["family_name"] != "白驼山派"))
		return notify_fail("你不是白驼山弟子，不能修炼西毒毒技。\n");
	if (me->query("shen")<=0) 
	  return notify_fail("修炼西毒毒技要心狠手辣，奸恶歹毒，你的表现还不够！\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("西毒毒技只能靠学习来提高。\n");
}
int help(object me)
{
	write(HIC"\n西毒毒技："NOR"\n");
	write(@HELP

    西毒弟子下毒必具武功，下毒的效果和西毒毒技的高低有很大
的关系。

	学习要求：
		名门正派的心法不能学
		非白驼山派弟子不能学
HELP
	);
	return 1;
}

