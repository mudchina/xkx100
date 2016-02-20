// mahayana.c 大乘涅磐功
//Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
/*
	if (!myfam || (myfam["family_name"] != "峨嵋派"))
		return notify_fail("你不是峨嵋弟子，不能修炼大乘涅磐功。\n");
	if (me->query_skill("linji-zhuang",1) < me->query_skill("mahayana",1))
		return notify_fail("你的本门内功修为太少，修炼大乘涅磐功也没用。\n");
*/
	if ((int)me->query("shen") < 0 )
		return notify_fail("你的邪气太重，无法修炼大乘涅磐功。\n");
//	if (me->query_skill("persuading",1) <= me->query_skill("mahayana",1))
//		return notify_fail("你的善行太少，修炼大乘涅磐功也没用。\n");
	if( (int)me->query_skill("taoism",1) > 1 )
		return notify_fail("你学了牛鼻子的心法，无法修炼大乘涅磐功。\n");
	if ((me->query_skill("lamaism",1) > 1))
		return notify_fail("你心存密宗，无法修炼大乘涅磐功。\n");
	if (me->query_skill("mahayana", 1) >= 200)
		return notify_fail("限于资质，你对大乘涅磐功的理解也就到此为止了。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("大乘涅磐功只能靠学习来提高。\n");
}
int help(object me)
{
	write(HIC"\n大乘涅磐功："NOR"\n");
	write(@HELP

    峨嵋派素不喜与人争斗，弟子门人常常闭门修炼以增长人体潜
能，其有效程度乃取决于佛法修为（即大乘涅磐功的等级）。打坐
静修可在峨嵋禅房使用命令jingzuo。请help jingzuo。

	学习要求：
		相应的临济十二庄
		不能学禅宗心法外的其他宗教心法
HELP
	);
	return 1;
}

