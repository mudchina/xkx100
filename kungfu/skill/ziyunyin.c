// ziyunyin.c 紫氲吟
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

#include <ansi.h>
void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	if( me->query_skill("zixia-shengong",1) < 30)
		return notify_fail(RANK_D->query_respect(me) + "，华山九功，紫霞第一，你学了多少？\n");
	if( me->query_skill("buddhism",1) > 1) 
		return notify_fail(RANK_D->query_respect(me)+"既参禅宗，如何能领会我华山以气御万物的道理？\n");
	if( (int)me->query_skill("taoism",1) > 1 )
		return notify_fail("你学了太上道祖之心法，如何能领会我华山以气御万物的道理？\n");
	if ((me->query_skill("poison",1) > 1))
		return notify_fail("哈哈！"+ RANK_D->query_respect(me)+"已经学了邪魔外道的毒技，怎么领会我堂堂紫氲吟？\n");
	if ((me->query_skill("lamaism",1) > 1))
		return notify_fail("哈哈！"+ RANK_D->query_respect(me)+"已经学了密宗心法，即非我正派中人！\n");
	if (me->query_skill("ziyunyin", 1) >= 100)
		return notify_fail("限于资质，你对紫氲吟的理解也就到此为止了。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("紫氲吟只能靠学(learn)来提高。\n");
}

int help(object me)
{
	write(HIC"\n紫氲吟："NOR"\n");
	write(@HELP

    紫氲吟为华山心法，配合紫霞神功能增加精。
    可寻找紫氲谱阅读。

	学习要求：
		紫霞神功30级
                与道家心法、禅宗心法、密宗心法和基本毒技不能兼学
HELP
	);
	return 1;
}

