// wuying-leg.c 无影腿
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N双手虚晃，左脚猛地飞起，一式"HIB"「无影无踪」"NOR"，脚尖晃动，踢向$n的屁股",	
	"lvl" : 0,
	"skill_name" : "无影无踪"
]),
([	"action" : "$N左脚顿地，别转身来抽身欲走，只一刹那间一回身，右脚一式"HIW"「无影乱舞」"NOR"，猛踹$n的$l",
	"lvl" : 10,
	"skill_name" : "无影乱舞"
]),
([	"action" : "$N左手一挣，反手扭搭住$n的右手，右脚同时踹出，既猛且准，一式"GRN"「丛丛叠叠」"NOR"，踢中的$n的胸口",
	"lvl" : 20,
	"skill_name" : "丛丛叠叠"
]),
([	"action" : "$N突然跃起，双足连环圈转，一式"YEL"「秋风扫叶」"NOR"，足带风尘，攻向$n的全身",
	"lvl" : 30,
	"skill_name" : "秋风扫叶"
]),
([	"action" : "$N两手护胸，双脚交叉踢起，一式"HIC"「腿扫残云」"NOR"，脚脚不离$n的面门左右",
	"lvl" : 40,
	"skill_name" : "腿扫残云"
]),
([	"action" : "$N突然侧身，却步后退，一个前空翻，右脚自上而下一式"HIM "「慧星坠地」"NOR"，照$n的面门直劈下来",
	"lvl" : 50,
	"skill_name" : "慧星坠地"
]),
([	"action" : "$N使一式"HIW"「东风吹雪」"NOR"，全身突然飞速旋转，双足忽前忽后，迅猛无极踹向$n的胸口",
	"lvl" : 60,
	"skill_name" : "东风吹雪"
]),
([	"action" : "$N抽身跃起，开声吐气，大喝一声：嗨！一式"HIY"「佛山无影」"NOR"，双脚如旋风般踢向$n的$l",
	"lvl" : 80,
	"skill_name" : "佛山无影"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_combine(string combo) { return combo=="cuixin-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("无影腿必须空手。\n");
	if ((int)me->query_skill("qingming-xuangong", 1) < 15)
		return notify_fail("你的青冥玄功火候不够，无法学无影腿。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练无影腿。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练无影腿。\n");
	me->receive_damage("qi", 45);
	me->add("neili", -40);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	{
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
	}
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 15;
	int d_e2 = 35;
	int p_e1 = -40;
	int p_e2 = 20;
	int f_e1 = 250;
	int f_e2 = 350;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuying-leg", 1);
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

int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"wuying-leg/" + action;
}

int help(object me) {
	write(HIC"\n无影腿："NOR"\n");
	write(@HELP

    无影腿是青城派的功夫。
    可与摧心掌互备。

	学习要求：
		青冥玄功15级
		内力100
HELP
	);
	return 1;
}

