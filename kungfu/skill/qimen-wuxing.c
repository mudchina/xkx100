// qimen-wuxing 奇门五行
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
	return notify_fail("奇门五行能靠学(learn)来提高。\n");
}
int valid_learn(object me) 
{
	if( me->query_skill("hubo",1))
    return notify_fail("你的杂念太多，一时无法领会奇门五行！\n");
  return 1;
}
int help(object me)
{
	write(HIC"\n奇门五行："NOR"\n");
	write(@HELP


    是东海桃花岛的独门功夫。相传桃花岛虽然地处海外，人迹罕
至，但岛上却是家传渊博，对奇门五行研究得很深。有了这门功夫，
再配上桃花岛的布阵箱就可以摆出奇门五行阵，把敌人困在阵内。

    array somebody  在布阵箱的配合下，可以对某人布阵，使其
身陷阵内。

    可以阅读《易经》系列书籍提高。


	学习要求：
		不能同时修习左右互博之术
HELP
	);
	return 1;
}

