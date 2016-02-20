// fuguanglueying.c  浮光掠影
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"只见$n一招"BLU"「似来还往」"NOR"，双脚一前一后，似进又腿，在$n一愣间躲过了攻击。\n",
	"但是$n使出"CYN"「蜻蜓点水」"NOR"，脚尖站地，身形东倒西歪间，破天冲起。\n",
	"$n一招"HIY"「飞黄腾达」"NOR"，身随意转，刹那间在原地转了七八十圈，突然往地上一坐，\n原是转晕了，却使$N落了空。\n",
	"可是$n一个"HIW"「白驹过隙」"NOR"，身形微侧，提气直纵，躲过$N攻击。\n",
	"却见$n使出"HIW"「浮光掠影」"NOR"，在原地留下一个幻象，真身躲到了一边。\n",
	"$n身形一顿，"HIB"「逝者如斯」"NOR"，身形平平掠出，在空中留下一道弧形。\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{ 
	if( (int)me->query_skill("hanbing-zhenqi", 1) < 10 )
	return notify_fail("你的寒冰真气不够精熟，无法领会浮光掠影。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，无法能练习浮光掠影。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -6);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.3; }

int help(object me)
{
	write(HIC"\n浮光掠影："NOR"\n");
	write(@HELP

    嵩山派轻功身法。

        学习要求：
            寒冰真气10级	   
HELP
	);
	return 1;
}

