// chunyang-quan.c 纯阳拳
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":
"只见$N身形一矮，大喝声中以拳化勾一个"HIW"「玄鹤捕食」"NOR"对准$n的$l戳了过去",
	"lvl" : 0,
	"skill_name" : "玄鹤捕食"
]),
([	"action":
"$N左手一分，身形扭转右拳运气，蜿蜒前伸，一招"HIY"「金蛇寻龟」"NOR"便往$n的$l
招呼过去",
	"lvl" : 20,
	"skill_name" : "金蛇寻龟"
]),
([	"action":
"$N右拳在$n面门一晃，和身向前一扑左拳使了个"HIB"「野马上槽」"NOR"往$n的$l狠命一抡",
	"lvl" : 40,
	"skill_name" : "野马上槽"
]),
([	"action":
"$N步履一沉，左拳拉开，右拳带风，一招"HIR"「黑虎掏心」"NOR"势不可挡地击向$n$l",
	"lvl" : 60,
	"skill_name" : "黑虎掏心"
]),
([	"action":
"只见$N拉开架式，一招"HIM"「二龙戏珠」"NOR"双拳齐出击向$n$l，虎虎有风",
	"lvl" : 80,
	"skill_name" : "二龙戏珠"
]),
([	"action":
"$N虚晃一拳，回身欲走，只霎那间身子一侧，反脚踢起，正是"RED"「麒麟反挂」"NOR"！",
	"lvl" : 100,
	"skill_name" : "麒麟反挂"
]),
([	"action":
"$N拉开后弓步，左拳一晃，右拳随出，左右拳掌交替变幻迭出，一招"GRN"「青龙
夺食」"NOR"往$n的$l攻去",
	"lvl" : 120,
	"skill_name" : "青龙夺食"
]),
([	"action":
"只见$N运足气力，一个纵身，右拳从左拳后侧身穿出，身随拳至，力势千钧！
这一招的名字叫作"HIR"「赤龙穿云」"NOR"",
	"lvl" : 140,
	"skill_name" : "赤龙穿云"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练纯阳拳必须空手。\n");
	if ((int)me->query_skill("xiantian-qigong", 1) < 20)
		return notify_fail("你的先天气功火候不够，无法学纯阳拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练纯阳拳。\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练纯阳拳。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 200;
	int f_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("chunyang-quan", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"chunyang-quan/" + action;
}
int help(object me)
{
	write(HIC"\n纯阳拳："NOR"\n");
	write(@HELP

    纯阳拳为王重阳所创的全真派拳法。
    可与昊天掌互备。

	学习要求：
		先天气元功20级
		内力100
HELP
	);
	return 1;
}

