// luohan-quan.c 罗汉拳
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N连续上步，一式"HIY"「黄莺落架」"NOR"，左右手分靠，变拳为掌，击向$n的
$l",
	"lvl" : 0,
	"skill_name" : "黄莺落架"
]),
([	"action" : "$N左脚虚踏，全身右转，一招"HIM"「丹凤朝阳」"NOR"，右掌猛地插向$n的$l",
	"lvl" : 8,
	"skill_name" : "丹凤朝阳"
]),
([	"action" : "$N双手大开大阖，宽打高举，使一招"HIB"「洛钟东应」"NOR"，双拳向$n的$l打
去",
	"lvl" : 15,
	"skill_name" : "洛钟东应"
]),
([	"action" : "$N左掌圈花扬起，屈肘当胸，虎口朝上，一招"HIC"「偏花七星」"NOR"打向$n的
$l",
	"lvl" : 24,
	"skill_name" : "偏花七星"
]),
([	"action" : "$N使一招"HIM"「苦海回头」"NOR"，上身前探，双手划了个半圈，击向$n的$l",
	"lvl" : 33,
	"skill_name" : "苦海回头"
]),
([	"action" : "$N双掌划弧，一记"HIY"「挟山超海」"NOR"，掌出如电，一下子切到$n的手上",
	"lvl" : 42,
	"skill_name" : "挟山超海"
]),
([	"action" : "$N施出"HIG"「慑服外道」"NOR"，双拳拳出如风，同时打向$n头，胸，腹三处要
害",
	"lvl" : 50,
	"skill_name" : "慑服外道"
]),
([	"action" : "$N左脚内扣，右腿曲坐，一式"BLU"「三入地狱」"NOR"，双手齐齐按向$n的胸口
",
	"lvl" : 58,
	"skill_name" : "三入地狱"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }	
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练罗汉拳必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候不够，无法学罗汉拳。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练罗汉拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练罗汉拳。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 110;
	int f_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luohan-quan", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : "瘀伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n罗汉拳："NOR"\n");
	write(@HELP

    罗汉拳为少林七十二绝技之一。
    可与互备。

	学习要求：
		混元一气功10级
		内力50
HELP
	);
	return 1;
}

