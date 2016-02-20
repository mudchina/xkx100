// persuading.c 渡世济人
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
	return notify_fail("渡世济人要在实践中提高。\n");
}
int help(object me)
{
	write(HIC"\n渡世济人："NOR"\n");
	write(@HELP

    峨嵋弟子崇信大乘佛教，悲天悯人，讲究渡人渡己，不仅仅是
只顾自己修行，所以渡世济人的功业乃是峨嵋派考量门人弟子的重
要标准。峨嵋弟子可用命令persuade劝服战斗中的玩家或者ＮＰＣ
罢斗，在实用中增长修为，并取得实战经验和潜能。
    请help persuade。

	学习要求：
		实践中获得
HELP
	);
	return 1;
}

