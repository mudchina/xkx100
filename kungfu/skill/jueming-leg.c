// jueming-leg.c 绝命腿
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$n用右脚钩踢$N左脚下盘，$N提脚避开$n锋芒，一招「黑虎蹬山」，\n迅速猛力地连续踹击$n的$l。",
	"lvl"   : 0,
	"skill_name" : "黑虎蹬山" 
]),
([	"action" : "$n右拳击$N头部，$N上体后闪，同时起右脚猛蹬$n腹部，「白猿登枝」，\n突然变侧踹腿猛力踹击$n$l。",
	"lvl"   : 10,
	"skill_name" : "白猿登枝" 
]),
([	"action" : "$N左拳撩拨$n拳头，右脚内侧踩击$n的胫骨，一招「虎尾搅林」\n侧踹腿攻击$n$l",
	"lvl"   : 20,
	"skill_name" : "虎尾搅林" 
]),
([	"action" : "$N用右脚钩踢$n左腿下盘，同时右钩踢突然横扫$n腰部，一招「风卷残叶」",
	"lvl"   : 30,
	"skill_name" : "风卷残叶" 
]),
([	"action" : "$n用右拳猛击$N面部，$N速用右里合腿挂拦$n腕部，一招「疾浪翻花」，\n变为侧踹腿踹$n的$l",
	"lvl"   : 40,
	"skill_name" : "疾浪翻花" 
]),
([	"action" : "$N突发右腿弹踢$n裆部，「浪子踢球」，右腿速变点脚猛力踢击$n之$l",
	"lvl"   : 60,
	"skill_name" : "浪子踢球" 
]),
([	"action" : "$N用右脚钩踢$n足根，使出「顺风扯旗」，顺势变为横腿，侧倒疾扫$n$l",
	"lvl"   : 80,
	"skill_name" : "顺风扯旗" 
]),
([	"action" : "$N起右脚弹踢$n档部，一招「野马奔蹄」，弹踢之腿疾变为侧踹腿，猛力攻击$n$l",
	"lvl"   : 100,
	"skill_name" : "野马奔蹄" 
]),
});

int valid_enable(string usage) { return  usage=="leg" || usage=="parry"; }
int valid_combine(string combo) { return combo=="huagu-mianzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练绝命腿必须空手。\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 20)
		return notify_fail("你的毒龙大法火侯不够，无法学绝命腿。\n");
	if ((int)me->query_skill("leg", 1) < 20)
		return notify_fail("你的基本腿法火侯不够，无法学绝命腿。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练绝命腿。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的气血太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练绝命腿。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
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
	int d_e1 = -60;
	int d_e2 = -30;
	int p_e1 = 0;
	int p_e2 = 30;
	int f_e1 = 220;
	int f_e2 = 320;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jueming-leg", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"jueming-leg/" + action;
}

int help(object me)
{
	write(HIC"\n绝命腿"NOR"\n");
	write(@HELP

    绝命腿招是神龙岛腿法，可与化骨绵掌互备。

	学习要求：
		毒龙大法20级
		基本腿法20级
		内力修为100
HELP
	);
	return 1;
}

