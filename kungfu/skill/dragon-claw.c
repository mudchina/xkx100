// Last Modified by Winder on May. 29 2001
// dragon-claw.c 龙爪功 和般若掌互备 取自《倚天屠龙记》。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "在呼呼风声中，$N使一招"CYN"「捕风式」"NOR"，双手如钩如戢，紧随$n，插向$p的$l",
	"lvl"    : 0,
	"skill_name" : "捕风式" ,		
]),
([	"action" : "$N猛地向前跃出，一招"BLU"「捉影式」"NOR"，身随$n游走，左右双手连抓，招招不离$n的面门",
	"lvl"    : 10,
	"skill_name" : "捉影式" ,		
]),
([	"action" : "$N双手平伸，十指微微上下抖动，打向$n的$l，这是一招华丽的"GRN"「抚琴式」"NOR"",
	"lvl"    : 20,
	"skill_name" : "抚琴式" ,		
]),
([	"action" : "$N左手上拦，右手内挥空抓，仿若握拳，一招"YEL"「击鼓式」"NOR"击向$n胸口，却是力大无比",
	"lvl"    : 30,
	"skill_name" : "击鼓式" ,		
]),
([	"action" : "$N右手虚握，左手掌立如山，一招"MAG"「批亢式」"NOR"，突然变招，左收右出，猛地击向$n的$l",
	"lvl"    : 40,
	"skill_name" : "批亢式" ,		
]),
([	"action" : "$N腾步上前，左手护胸，右手探出，这一招"HIW"「掏虚式」"NOR"抓向$n的$l，使得痛快淋漓",
	"lvl"    : 50,
	"skill_name" : "掏虚式" ,		
]),
([	"action" : "$N双手平提胸前，左手护住面门，一招"HIB"「抱残式」"NOR"，身体一转，闪在$n身旁，右手推向$p的$l",
	"lvl"    : 60,
	"skill_name" : "抱残式" ,		
]),
([	"action" : "$N两手胸前环抱，腋下含空，一爪而出，五指如钩，一招"HIM"「守缺式」"NOR"插向$n的顶门",
	"lvl"    : 70,
	"skill_name" : "守缺式" ,		
]),
([	"action" : "$N右腿斜插$n二腿之间，一招"HIR"「抢珠式」"NOR"，上手取目诱敌，下手反勾$n的$l",
	"lvl"    : 80,
	"skill_name" : "抢珠式" ,		
]),
([	"action" : "$N一手虚指$n的剑诀，一招"CYN"「夺剑式」"NOR"，一手劈空抓向$n，抓内中空，仿佛握有长剑",
	"lvl"    : 100,
	"skill_name" : "夺剑式" ,		
]),
([	"action" : "$N左手抓向$n胸前的五道大穴，右手斜劈太阳穴，一招"HIW"「拿云式」"NOR"使得$n进退两难",
	"lvl"    : 120,
	"skill_name" : "拿云式" ,		
]),
([	"action" : "$N前脚着地，一手顶天成爪，一手指地，一招"RED"「追日式」"NOR"后出先至，劲气笼罩$n的全身",
	"lvl"    : 150,
	"skill_name" : "追日式" ,		
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo){ return combo=="boruo-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练龙爪功必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 80)
		return notify_fail("你的站桩功火候不够，无法学龙爪功。\n");
	if ((int)me->query("max_neili") < 800)
		return notify_fail("你的内力太弱，无法练龙爪功。\n");
	if ((me->query_skill("nianhua-finger", 1) < 50) ||
		(me->query_skill("eagleg-claw", 1) < 50))
		return notify_fail("你的拈花指和鹰爪功火候不够，无法学龙爪功。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练龙爪功。\n");
	me->receive_damage("qi", 50);
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
	int d_e1 = 30;
	int d_e2 = 5;
	int p_e1 = -20;
	int p_e2 = -50;
	int f_e1 = 300;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("dragon-claw", 1);
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
		"damage_type" : random(2) ? "内伤" : "抓伤",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"dragon-claw/" + action;
}

int help(object me)
{
	write(HIC"\n龙爪功："NOR"\n");
	write(@HELP

    龙爪功是南少林爪法，和般若掌互备。

	学习要求：
		站桩功80级
		拈花指50级
		鹰爪功50级
		内力修为800
HELP
	);
	return 1;
}

