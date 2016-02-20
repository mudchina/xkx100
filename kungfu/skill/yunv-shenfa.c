// yunv-shenfa.c 玉女身法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"但是$n身形一转，使出"HIW"「麝熏微度」"NOR"，蓦地不见，避开了这一招。\n",
	"$n一招"HIW"「西施浣纱」"NOR"，身随意转，倏地往一旁挪开了三尺。\n",
	"$n身形飘忽，瞻之在前，忽焉在后，却是"HIW"「走马兰台」"NOR"的身法。\n",
	"$n使出"HIW"「洛河清波」"NOR"，犹如在水面滑行一般，身形晃了开去。\n",
	"可是$n的身影飘飘渺渺，竟丝毫不着力，是一式"HIW"「蓬山万重」"NOR"的身法。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("yunv-xinfa", 1) < 10 )
	return notify_fail("你的玉女心法不够精熟，无法领会玉女身法。\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40|| (int)me->query("neili") < 8 )
		return notify_fail("你的体力太差了，不能练玉女身法。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -8);	
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.4; }

int help(object me)
{
	write(HIC"\n玉女身法："NOR"\n");
	write(@HELP

    古墓派轻功妙绝天下，飘逸灵动、变化万方，于丈许方圆之内
更是趋退若神，当世无比。

	学习要求：
	  玉女心法10级
HELP
	);
	return 1;
}

