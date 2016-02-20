// Last Modified by Winder on May. 29 2001
// eagleg-claw.c 鹰爪功 和捻花指互备

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N全身拔地而起，半空中一个筋斗，一式"HIB"「凶鹰袭兔」"NOR"，迅猛地抓向$n的$l",
	"lvl"   : 0,
	"skills_name" : "凶鹰袭兔",
]),
([	"action" : "$N单腿直立，双臂平伸，全身一转，一式"HIY"「雄鹰展翅」"NOR"，双爪一前一后拢向$n的$l",
	"lvl"   : 10,
	"skills_name" : "雄鹰展翅",
]),
([	"action" : "$N一式"HIM"「拔翅横飞」"NOR"，全身向斜里平飞，右腿一绷，双爪飞落，搭向$n的$l",
	"lvl"   : 20,
	"skills_name" : "拔翅横飞",
]),
([	"action" : "$N双爪交错上举，使一式"HIC"「迎风振翼」"NOR"，一拔身，凌空而起，分别袭向$n左右空门",
	"lvl"   : 30,
	"skills_name" : "迎风振翼",
]),
([	"action" : "$N全身滚动上前，一式"HIM"「飞龙献爪」"NOR"，爪影中右爪猛地突出，鬼魅般抓向$n的胸口",
	"lvl"   : 40,
	"skills_name" : "飞龙献爪",
]),
([	"action" : "$N伏地滑行，一式"HIW"「拨云瞻日」"NOR"，双抓一翻，上手袭向膻中大穴，下手反抓$n的$l",
	"lvl"   : 50,
	"skills_name" : "拨云瞻日",
]),
([	"action" : "$N左右手掌爪互逆，跃起一式"CYN"「搏击长空」"NOR"，无数道劲气直指尖破空而出，迅疾无比地击向$n",
	"lvl"   : 55,
	"skills_name" : "搏击长空",
]),
([	"action" : "$N腾空高飞三丈，一式"RED"「鹰扬万里」"NOR"，长啸一声，于天空中幻化出一个巨灵爪影，缓缓罩向$n",
	"lvl"   : 60,
	"skills_name" : "鹰扬万里",
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo){ return combo=="nianhua-finger"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练鹰爪功必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 60)
		return notify_fail("你的易筋经内功火候不够，无法学鹰爪功。\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail("你的内力太弱，无法练鹰爪功。\n");
	if ((me->query_skill("jimie-claw", 1) < 50) ||
		(me->query_skill("jingang-strike", 1) < 50))
		return notify_fail("你的大金刚神掌和寂灭爪火候不够，无法学鹰爪功。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练鹰爪功。\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 50;
	int d_e2 = 20;
	int p_e1 = -10;
	int p_e2 = -30;
	int f_e1 = 200;
	int f_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("eagleg-claw", 1);
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
		"damage_type" : random(2) ? "瘀伤" : "抓伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	 return __DIR__"eagleg-claw/" + action;
}

int help(object me)
{
	write(HIC"\n鹰爪功："NOR"\n");
	write(@HELP

    鹰爪功是南少林爪法，和拈花指互备。

	学习要求：
		站桩功60级
		大金刚神掌50级
		寂灭爪50级
		内力修为600
HELP
	);
	return 1;
}

