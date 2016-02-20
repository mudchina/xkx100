// lamaism.c 密宗心法
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
	if ((me->query_skill("buddhism",1) > 1) ||
		(me->query_skill("mahayana",1) > 1))
		return notify_fail("哈哈！"+RANK_D->query_respect(me)+ "既入禅门，怎么却来学密宗心法？\n");
	if( (int)me->query_skill("taoism",1) > 1 )
		return notify_fail("你学了牛鼻子的心法，无法修炼密宗心法。\n");
	if ((me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail("哈哈！"+RANK_D->query_respect(me)+ "已经学了伪君子的心法，怎么却来学密宗心法？\n");
	if ((me->query_skill("poison",1) > 1))
		return notify_fail("哈哈！"+RANK_D->query_respect(me)+ "已经学了邪魔外道的毒技，怎么却来学密宗心法？\n");
	if (me->query_skill("lamaism", 1) >= 150)
		return notify_fail("限于资质，你对密宗心法的理解也就到此为止了。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("密宗心法只能靠学(learn)来提高。\n");
}

int help(object me)
{
	write(HIC"\n密宗心法："NOR"\n");
	write(@HELP

    密宗心法是雪域密宗心法，用以超渡生灵。

	学习要求：
		不可学禅宗、道家和华山的心法以及星宿毒技
HELP
	);
	return 1;
}

