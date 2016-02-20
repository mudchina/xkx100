// Last Modified by winder on May. 29 2001
// fengyun-hand.c 风云手 和罗汉拳互备

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"CYN"「风满长空」"NOR"，双手以掌化爪，五指如钩，挟着风声直逼$n的膻中要穴",
	"limb" : "膻中穴",
	"lvl" : 0,
	"skill_name" : "风满长空"
]),
([	"action" : "$N一式"RED"「烈火腾云」"NOR"，右手上下挥动化成迷雾，接着左手一探，反扣$n的肩井大穴",
	"lvl" : 8,
	"limb" : "肩井穴",
	"skill_name" : "烈火腾云"
]),
([	"action" : "$N使一式"GRN"「草深雾泽」"NOR"，掌指齐出，幻出无数幻影，风声中右手按向$n的胸前要害",
	"lvl" : 16,
	"skill_name" : "草深雾泽"
]),
([	"action" : "$N左手成掌，右手握拳，一式"BLU"「天目昭辉」"NOR"，拉出的拳影掌影有如云雾变幻一般，罩向$n",
	"lvl" : 24,
	"skill_name" : "天目昭辉"
]),
([	"action" : "$N使一式"YEL"「雷震四方」"NOR"，双手挥动，四面八方出现无数掌影，跟着一爪突出，抓向$n$l",
	"lvl" : 40,
	"skill_name" : "雷震四方"
]),
([	"action" : "$N两手环扣，双臂如流云般晃动，一式"CYN"「水到渠成」"NOR"，节节进逼，将$n拉入招中",
	"lvl" : 48,
	"skill_name" : "水到渠成"
]),
([	"action" : "$N一式"GRN"「山高林密」"NOR"，一掌拍出飞天沙石，然后十指齐伸，遮天蔽日般地笼罩$n的全身要穴",
	"lvl" : 54,
	"skill_name" : "山高林密"
]),
([	"action" : "$N岳立霆峙，一式"YEL"「地老天荒」"NOR"，在一阵暴雷风云声中，双手同时拍中$n的七道死穴",
	"lvl" : 100,
	"skill_name" : "地老天荒"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo){ return combo=="luohan-cuff"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练风云手必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 10)
		return notify_fail("你的站桩功火候不够，无法学风云手。\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的内力太弱，无法练风云手。\n");
	if (me->query_skill("shaolin-cuff", 1) < 10 )
		return notify_fail("你还未掌握少林南拳，无法学习风云手。\n");

	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
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
	int d_e1 = -30;
	int d_e2 = 0;
	int p_e1 = 30;
	int p_e2 = 60;
	int f_e1 = 60;
	int f_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("fengyun-hand", 1);
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

string perform_action_file(string action)
{
	 return __DIR__"fengyun-hand/" + action;
}

int help(object me)
{
	write(HIC"\n风云手："NOR"\n");
	write(@HELP

    风云手是南少林入门手法。和罗汉拳互备。

	学习要求：
		站桩功10级
		少林南拳10级
		内力修为10
HELP
	);
	return 1;
}

