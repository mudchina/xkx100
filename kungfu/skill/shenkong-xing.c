// shenkong-xing.c 身空行
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n使出一招"HIC"「心空」"NOR"，身体向侧后飘去 \n",
	"$n使出一招"HIW"「誓言空」"NOR"，双足一点，跃至数丈之外 \n",
	"$n使出一招"HIM"「莲空」"NOR"，身形一变，滑至$N身后 \n",
	"$n大吼一声，使出一招"HIG"「大安空」"NOR"，从$N头顶越过 \n",
	"$n使出一招"HIY"「佛空」"NOR"，如轻鸿般飘去，瞬间又闪至$N面前 \n",
	"$n使出一招"HIR"「金刚空」"NOR"，顿时$N周围都是$n的身影 \n",
});

int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("xiaowuxiang", 1) < 10 )
	return notify_fail("你的小无相功不够精熟，无法领会身空行。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 10|| (int)me->query("neili") < 2 )
		return notify_fail("你的体力太差了，不能练身空行。\n");
	me->receive_damage("qi", 10);
	me->add("neili", -4);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.1; }

int help(object me)
{
	write(HIC"\n身空行："NOR"\n");
	write(@HELP

    身空行是雪山寺弟子本门轻功身法。

	学习要求：
	  小无相功10级
HELP
	);
	return 1;
}

