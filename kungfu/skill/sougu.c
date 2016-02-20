// sougu.c 搜骨鹰爪功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N双臂一拢，左爪直攻$n下盘，右爪却挟风雷之势推向$n腰间，一虚一实，正是一招"HIM"「推爪式」"NOR"",
	"lvl"    : 0,
	"skill_name" : "推爪式"
]),
([	"action" : "$N身形陡起，如雄鹰击日般“倏”地从$n头顶越过，使一招"HIR"「盖爪式」"NOR"双爪疾向$n脑后击下",
	"lvl"    : 5,
	"skill_name" : "盖爪式"
]),
([	"action" : "$N就地一滚，突然到了$n身前，使一招"HIB"「掏爪式」"NOR"，右爪直奔$n小腹",
	"lvl"    : 10,
	"skill_name" : "掏爪式"
]),
([	"action" : "\n$N左爪护胸，右爪凝劲后发，一招"HIC"「托爪式」"NOR"，缓缓托向$n的$l",
	"lvl"    : 20,
	"skill_name" : "托爪式"
]),
([	"action" : "\n$N身形诡异，疾速前扑，使一招"HIG"「撩爪式」"NOR"，直撩$n裆部",
	"lvl"    : 35,
	"skill_name" : "撩爪式"
]),
([	"action" : "\n$N身形飘忽，陡然转到$n身后，一招"HIW"「锁爪式」"NOR"，双爪直向$n咽喉插下",
	"lvl"    : 60,
	"skill_name" : "锁爪式"
]),
([	"action" : "\n$N一声厉啸，身形拔起，使出"HIC"「千爪式」"NOR"，由半空盘旋下击，$n顿觉漫天爪影，罩向全身死穴",
	"lvl"    : 85,
	"skill_name" : "千爪式"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练搜骨鹰爪功必须空手。\n");
	if (me->query_skill("jiuyang-shengong") < 30)
		return notify_fail("你的九阳神功太弱，无法学搜骨鹰爪功。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法学搜骨鹰爪功。\n");
	if ((int)me->query("str") < 24)
		return notify_fail("你的膂力太差，无法学搜骨鹰爪功。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练鹰爪功。\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = 40;
	int d_e2 = 20;
	int p_e1 = -10;
	int p_e2 = -40;
	int f_e1 = 250;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("sougu", 1);
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
		"damage_type" : random(2) ? "抓伤" : "内伤",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"sougu/" + action;
}
int help(object me)
{
	write(HIC"\n搜骨鹰爪功："NOR"\n");
	write(@HELP

    明教白眉鹰王殷天正之绝招，又手似鹰爪，手到擒来。是明教
的入门武功。

	学习要求：
		先天膂力24
		九阳神功30级
		内力100
HELP
	);
	return 1;
}

