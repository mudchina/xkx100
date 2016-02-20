// fengyun-shou.c 风云手
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIC"「风满长空」"NOR"，以掌化爪，五指如钩，直逼$n的膻中要穴",
	"lvl" : 0,
	"skill_name" : "风满长空"
]),
([	"action" : "$N左手虚晃，一式"HIR"「烈火腾云」"NOR"，右手上下直击，反扣$n的肩井大穴
",
	"lvl" : 8,
	"skill_name" : "烈火腾云"
]),
([	"action" : "$N使一式"HIG"「草深雾泽」"NOR"，掌指齐出，拍拿并施，拿向$n的三路要害",
	"lvl" : 16,
	"skill_name" : "草深雾泽"
]),
([	"action" : "$N左手鹰抓，右手蛇举，一式"HIW"「天目昭辉」"NOR"疾扣$n的中节大脉",	
	"lvl" : 24,
	"skill_name" : "天目昭辉"
]),
([	"action" : "$N使一式"HIM"「雷震四方」"NOR"，四面八方出现无数掌影，一爪突出，抓向$n
的胸口",
	"lvl" : 40,
	"skill_name" : "雷震四方"
]),
([	"action" : "$N两手环扣，全身关节啪啪作响，一式"HIC"「水到渠成」"NOR"，击向$n的$l",
	"lvl" : 48,
	"skill_name" : "水到渠成"
]),
([	"action" : "$N一式"HIB"「山高林密」"NOR"，十指齐伸，遮天蔽日般地笼罩$n的全身要穴",
	"lvl" : 54,
	"skill_name" : "山高林密"
]),
([	"action" : "$N岳立霆峙，一式"HIY"「地老天荒」"NOR"，在一阵暴雷声中，双手同时拍中$n
的七道死穴",
	"lvl" : 60,
	"skill_name" : "地老天荒"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yingzhua-gong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练风云手必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学风云手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练风云手。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练风云手。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -10);
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
	int d_e1 = -35;
	int d_e2 = 0;
	int p_e1 = 30;
	int p_e2 = 55;
	int f_e1 = 70;
	int f_e2 = 170;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("fengyun-shou", 1);
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
	write(HIC"\n风云手："NOR"\n");
	write(@HELP

    风云手为少林七十二绝技之一。
    可与鹰爪功互备。

	学习要求：
		混元一气功20级
HELP
	);
	return 1;
}

