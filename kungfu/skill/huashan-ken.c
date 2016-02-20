// huashan-ken.c 华山拳法
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":  "$N使一招"HIW"「云里乾坤」"NOR"左拳击出，不等招式使老，右拳已从左拳之底穿出，对准$n的$l「呼」地一拳",
	"skill_name": "云里乾坤",
	"lvl": 0,
]),
([	"action":  "$N左拳突然张开，拳开变掌，直击化为横扫，一招"HIC"「雾里看花」"NOR"便往$n的$l招呼过去",
	"skill_name": "雾里看花",
	"lvl": 10,
]),
([	"action":  "$N两手虎口相对，往内一圈，一招"HIY"「金鼓齐鸣」"NOR"往$n的$l击出",
	"skill_name": "金鼓齐鸣",
	"lvl": 20,
]),
([	"action":  "$N步履一沉，左拳虚晃一招，右拳使出"MAG"「梅花弄影」"NOR"击向$n$l",
	"skill_name": "梅花弄影",
	"lvl": 30,
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练华山拳法必须空手。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("你的紫霞神功不熟练，无法练华山拳法。\n");	
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -20);
	return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 40;
	int d_e2 = 60;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 100;
	int f_e2 = 200;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("huashan-ken", 1);
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
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n华山拳法："NOR"\n");
	write(@HELP

    华山拳法为华山气宗拳法。

	学习要求：
	   紫霞10级
HELP
	);
	return 1;
}

