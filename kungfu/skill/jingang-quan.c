// jingang-quan.c -大金刚拳
// Last Modified by sega on Mar. 10 2000
// 少林的招牌空手功夫，不能差了

#include <ansi.h>
inherit "/inherit/skill/cuff.c";
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N盘膝而坐，二手合十，一式"HIC"「莲花座」"NOR"，双拳蓄势而发，击向$n的$l",
	"lvl" : 0,
	"skill_name" : "莲花座"
]),
([	"action" : "$N一式"HIR"「烈火锥」"NOR"，双掌轮流下击，拳势如焰，吡啪爆响",
	"lvl" : 10,
	"skill_name" : "烈火锥"
]),
([	"action" : "$N腾空飞起，一式"HIG"「八方雨」"NOR"，双手双腿齐出，令$n无可躲藏",	
	"lvl" : 20,
	"skill_name" : "八方雨"
]),
([	"action" : "$N双掌虚含，掌缘下沉，一式"HIM"「掌心雷」"NOR"，缓缓向$n推出",
	"lvl" : 30,
	"skill_name" : "掌心雷"
]),
([	"action" : "$N一臂前伸，一臂后指，一式"HIB"「五指山」"NOR"，攻向$n的身前身后",	
	"lvl" : 40,
	"skill_name" : "五指山"
]),
([	"action" : "$N一式"HIW"「观音渡」"NOR"，两手十指虚点$n的全身三十六道要穴",
	"lvl" : 48,
	"skill_name" : "观音渡"
]),
([	"action" : "$N两目内视，双手内笼，一式"HIY"「天龙唱」"NOR"，四面八方响起震人心魄的
龙吟",
	"lvl" : 54,
	"skill_name" : "天龙唱"
]),
([	"action" : "$N似笑非笑，双拳无形无定，一式「如来笑」，骤然击向$n的前胸",
	"lvl" : 60,
	"skill_name" : "如来笑"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }	 
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练大金刚拳必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
		return notify_fail("你的混元一气功火候不够，无法学大金刚拳。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练大金刚拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练大金刚拳。\n");
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
	int d_e1 = 15;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -15;
	int f_e1 = 200;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jingang-quan", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"jingang-quan/" + action;
}

int help(object me)
{
	write(HIC"\n大金刚拳："NOR"\n");
	write(@HELP

    大金刚拳为少林七十二绝技之一。
    大金刚拳以天资所限，大多少林和尚均无法练成。少林派往往
要隔上百余年，才有一个特出的奇才能练成这门拳法。只是练功的
诀窍等等，上代高僧详记在武经之中，有时全寺数百僧众竟无一人
练成，却也不致失传。

	学习要求：
		混元一气功50级
		内力200
HELP
	);
	return 1;
}

