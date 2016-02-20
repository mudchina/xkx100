// zhentian-cuff.c 震天拳法

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N马步一立，身子微曲，暗喝一声，一招"HIW"「望月拜天」"NOR"，一拳直捅$n的$l",
	"lvl" : 0,
	"skill_name" : "望月拜天"
]),
([	"action" : "$N“哈哈”一笑，左拳由下至上，右拳平平击出，一招"RED"「跨日向天」"NOR"，交替打向$n",
	"lvl" : 15,
	"skill_name" : "跨日向天"
]),
([	"action" : "$N对$n一声大喝，使一招"HIC"「长虹经天」"NOR"，左拳击出，随即右拳跟上，两重力道打向$n的$l",
	"lvl" : 30,
	"skill_name" : "长虹经天"
]),
([	"action" : "$N闷喝一声，双拳向上分开，一记"HIR"「举火烧天」"NOR"，拳划弧线，左右同时击向$n的$l",
	"lvl" : 45,
	"skill_name" : "举火烧天"
]),
([	"action" : "$N施出"YEL"「一臂擎天」"NOR"，一声大吼，一拳凌空打出，拳风直逼$n的$l",
	"lvl" : 60,
	"skill_name" : "一臂擎天"
]),
([	"action" : "$N一声长啸，双拳交错击出，一招"BLU"「石破天惊」"NOR"，拳风密布$n的前后左右",
	"lvl" : 70,
	"skill_name" : "石破天惊"
]),
([	"action" : "$N怒吼一声，凌空飞起，一式"MAG"「天崩地裂」"NOR"，双拳居高临下，齐齐捶向$n",
	"lvl" : 80,
	"skill_name" : "天崩地裂"
]),
([	"action" : "$N仰天大笑，势若疯狂，衣袍飞舞，一招"HIW"「无法无天」"NOR"，拳风凌厉，如雨点般向$n打去",
	"lvl" : 90,
	"skill_name" : "无法无天"
]),
([	"action" : "$N手中招式突然加快，一招"MAG"「拳腿双绝」"NOR"，隔空向$n击出一拳，随即双腿连环踢出",
	"lvl" : 100,
	"skill_name" : "拳腿双绝"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="chuanyun-leg"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练「震天拳」必须空手。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 25)
		return notify_fail("你的「玄天无极功」火候不够，无法学「震天拳」。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练「震天拳」。\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的力气不够了。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的内力不够练「震天拳」。\n");
	me->receive_damage("qi", 35);
	me->add("qi", -20);
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
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 140;
	int f_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zhentian-cuff", 1);
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
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) {
	if (me->query("gender")=="男性")
	return 1.2;
	else
	 return 0.8; 
}

int help(object me)
{
	write(HIC"\n震天拳法："NOR"\n");
	write(@HELP

    震天拳法为昆仑派侧重男弟子的武技。

	学习要求：
		玄天无极功25级
		内力50
HELP
	);
	return 1;
}

