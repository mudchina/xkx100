// taoism.c 道学心法
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
	int lvl;

	lvl = (int)me->query_skill("taoism", 1);

	if( (int)me->query("shen") < 0 )
		return notify_fail("你的戾气太重，无法修炼道学心法。\n");
	if(me->query("gender") == "无性" && lvl > 39)
		return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之
气，无法领会里面的阴阳变化之道。\n");
	if ((me->query_skill("buddhism",1) > 1) ||
		(me->query_skill("mahayana",1) > 1))
		return notify_fail( "哈哈！"+RANK_D->query_respect(me)+"既入佛门，怎么却来学道学心法？\n");
	if ((int)(me->query_skill("lamaism",1) > 1))
		return notify_fail( "哈哈！"+RANK_D->query_respect(me)+"已经学了密宗心法，怎么却来学道学心法？\n");
	if ((me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail( "哈哈！"+RANK_D->query_respect(me)+"已经学了华山派的心法，怎么却来学道学心法？\n");
	if ((int)(me->query_skill("poison",1) > 1))
		return notify_fail( "哈哈！"+RANK_D->query_respect(me)+"已经学了邪魔外道的毒技，怎么却来学道学心法？\n");
	if (me->query_skill("taoism", 1) >= 150)
		return notify_fail("限于资质，你对道学心法的理解也就到此为止了。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("道学心法只能靠学习来提高。\n");
}

int help(object me)
{
        write(HIC"\n道学心法："NOR"\n");
        write(@HELP

    太上道祖传下的道德真言五千字中蕴涵的博大精深的心法。
    可寻找道德经阅读。

        学习要求：
                与禅宗心法、密宗心法、紫氲吟、正气诀和基本毒技不能兼学
HELP
        );
        return 1;
}

