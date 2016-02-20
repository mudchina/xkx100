// poyun-hand.c 破云手
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N双臂一拢，左爪直攻$n下盘，右爪却挟风雷之势推向$n腰间，一虚一实，正是一招"BLU"「翻云覆雨」"NOR"",
	"lvl"    : 0,
	"skill_name"  : "翻云覆雨"
]),
([	"action" : "$N身形陡起，如雄鹰击日般“倏”地从$n头顶越过，使一招"CYN"「排山倒海」"NOR"双手疾向$n脑后拍下",
	"lvl"    : 10,
	"skill_name"  : "排山倒海"
]),
([	"action" : "$N就地一滚，突然到了$n身前，使一招"MAG"「风卷残云」"NOR"，双手直拍$n小腹",
	"lvl"    : 20,
	"skill_name"  : "风卷残云"
]),
([	"action" : "$N左手护胸，右手凝劲后发，一招"HIC"「云过天晴」"NOR"，缓缓托向$n的$l",
	"lvl"    : 40,
	"skill_name"  : "云过天晴"
]),
([	"action" : "$N微微一笑，疾速前扑，使一招"HIW"「梦幻尘缘」"NOR"，直拍$n胸前三大要穴",
	"lvl"    : 60,
	"skill_name"  : "梦幻尘缘"
]),
([	"action" : "$N身形诡异，忽左忽右，陡然转到$n身后，一招"HIR"「电光火石」"NOR"，双手直向$n咽喉插下",
	"lvl"    : 80,
	"skill_name"  : "电光火石"
]),
([	"action" : "$N一声长啸，身形突然拔起，使出"HIG"「如水中月」"NOR"，由半空盘旋下击，$n顿觉漫天掌影，罩向全身要穴",
	"lvl"    : 100,
	"skill_name"  : "如水中月"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="songyang-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练破云手必须空手。\n");
	if ((int)me->query_skill("hanbing-zhenqi", 1) < 10)
		return notify_fail("你的寒冰真气火候不够，无法学破云手。\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的内力太弱，无法学破云手。\n");
	if ((int)me->query("str") < 25)
		return notify_fail("你的臂力太差，无法学破云手。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练破云手。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -20);
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
	int d_e1 = -40;
	int d_e2 = -10;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 120;
	int f_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("poyun-hand", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"poyun-hand/" + action;
}

int help(object me)
{
	write(HIC"\n破云手："NOR"\n");
	write(@HELP

    破云手为嵩山派手法。可与大嵩阳掌互备。

	学习要求：
		寒冰真气10级
		先天膂力25
		内力10
HELP
	);
	return 1;
}

