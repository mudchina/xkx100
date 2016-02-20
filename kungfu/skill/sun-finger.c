// sun-finger.c 一阳指 book: 一阳指诀
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"GRN"「阳关三叠」"NOR"，真气自指间喷薄而出，连出三指，快如电闪，点向$n的$l",
	"lvl" : 0,
	"skill_name" : "阳关三叠"
]),
([	"action" : "$N身形一转，一步跨到$n身后。$n急忙转身，$N又如闪电般跃回，
一式"YEL"「鲁阳返日」"NOR"，右手食指疾出，指向$n的$l",
	"lvl" : 20,
	"skill_name" : "鲁阳返日"
]),
([	"action" : "$N向左踏出一步，左手轻扬，右手食指挟着雄浑内力疾点$n的$l，
招式光明坦荡，正是一式"HIW"「阳春白雪」"NOR"",
	"lvl" : 40,
	"skill_name" : "阳春白雪"
]),
([	"action" : "$N身影飘起，一式"MAG"「阳钩挥天」"NOR"，自上而下，左脚弯曲如钩，踹向$n的右肩，$n侧身相避，$N右手趁势点向$n的$l",
	"lvl" : 60,
	"skill_name" : "阳钩挥天"
]),
([	"action" : "只见$N脸上忽地一红，左手一收，一式"RED"「烈日骄阳」"NOR"，右手食指斜指，向$n的$l点去",
	"lvl" : 70,
	"skill_name" : "烈日骄阳"
]),
([	"action" : "$N左掌斜削，突然间变掌为指，嗤的一声响，一式"HIM"「丹凤朝阳」"NOR"，使出一阳指力，疾点$n的$l",
	"lvl" : 90,
	"skill_name" : "丹凤朝阳"
]),
([	"action" : "$N反身一跃，闪身到$n背后，左膝一屈，右手食指回身一式"BLU"「阴阳交错」"NOR"，射向$n的后脑",
	"lvl" : 100,
	"skill_name" : "阴阳交错"
]),
([	"action" : "$N一声大吼, 一式"HIY"「三阳开泰」"NOR"，用尽全力向$n的$l点去",
	"lvl" : 130,
	"skill_name" : "三阳开泰"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
	if (me->query("gender") != "男性")
		return notify_fail("你阳气不足，无法学一阳指。\n");
	if ((int)me->query("max_neili") < 700)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
	if ((int)me->query_skill("kurong-changong", 1) > 80 ||
		(int)me->query_skill("xiantian-qigong", 1) > 80)
		return 1;
	else
		return notify_fail("你的本门内功火候不够，无法学一阳指。\n");
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练一阳指!\n");
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
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 390;
	int f_e2 = 490;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("sun-finger", 1);
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
		"damage_type" : random(2) ? "刺伤" : "瘀伤",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) 
{
  if(me->query_skill("kurong-changong") > 10) return 1.0;
  else return 0.6;
}


string perform_action_file(string action)
{
	return __DIR__"sun-finger/" + action;
}
int help(object me)
{
	write(HIC"\n一阳指："NOR"\n");
	write(@HELP

    原为大理段氏独门招牌武功，当年一灯大师段智兴挟此技参与
华山论剑，获得南帝称号。后一灯大师用一阳指和重阳真人交换先
天气功，此技亦流入全真派中。
    可与全真教昊天掌互备。

	学习要求：
		男性
		枯荣禅功或先天气功80级
		内力700
HELP
	);
	return 1;
}

